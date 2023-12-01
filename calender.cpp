#include <stdio.h>

int main(void) {
    int day = -1;
    int month = -2;
    int year = -3;

    while (day != 0 || month != 0 || year != 0) {
        printf("Enter a date (0 0 0 to quit):");
        scanf("%d %d %d", &day, &month, &year);

        if (day == 0 && month == 0 && year == 0) {
            printf("Thanks for using my calendar!");
        } else if (day <= 31 && month <= 12) {

            if (year < 0) {
                printf("This is not a valid date!");
            } else if (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)) {
                // January, March, May, July, August
                printf("The next day of 31.%02d.%d is 01.%02d.%d", month, year, month + 1, year);
            } else if (day == 28 && month == 2) {
                // February
                if (year % 4 != 0) {
                    // February goes to 28
                    printf("The next day of %02d.%02d.%d is 01.03.%d", day, month, year, year);
                } else {
                    // February goes to 29
                    printf("The next day of %02d.%02d.%d is 29.02.%d", day, month, year, year);
                }
            } else if (day == 29 && month == 2 && year % 4 == 0) {
                // After 29 February
                printf("The next day of %02d.%02d.%d is 01.03.%d", day, month, year, year);
            } else if (day == 29 && month == 2 && year % 4 != 0) {
                // After 29 February
                printf("This is not a valid date!");
            } else if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
                // April, June
                printf("The next day of 31.%02d.%d is 01.%d02.%d", month, year, month + 1, year);
            }

            else if ((day < 31 && day > 0) && (month > 0 && month <= 12)) {
                printf("The next day of %02d.%02d.%d is %02d.%02d.%d", day, month, year, day + 1, month, year);
            } else if ((day < 28 && day > 0) && month == 2) {
                printf("The next day of %02d.%02d.%d is %02d.%02d.%d", day, month, year, day + 1, month, year);
            } else if ((day == 31) && (month == 12)) {
                printf("The next day of 31.12.%d is 01.01.%d", year, year + 1);
            } else {
                printf("This is not a valid date!");
            }
        } else {
            printf("This is not a valid date!");
        }

        puts("");
    }
    return 0;
}

