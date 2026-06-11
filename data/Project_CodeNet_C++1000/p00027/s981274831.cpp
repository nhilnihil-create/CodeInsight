#include <cstdio>

int main() {
    int inm = 0;
    int ind = 0;
    while (scanf("%d %d", &inm, &ind) != EOF) {
        if ((inm == 0) && (ind == 0)) {
            break;
        }

        const int m[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int d = 2;

        for (int i = 0; i < inm; ++i) {
            for (int j = 0; j < m[i]; ++j) {
                if (d == 6) {
                    d = 0;
                } else {
                    d++;
                }

                if ((i == inm - 1) && (j == ind - 1)) {
                    goto end;
                }
            }
        }

        end:
        switch (d) {
        case 0:
            printf("Monday\n");
            break;
        case 1:
            printf("Tuesday\n");
            break;
        case 2:
            printf("Wednesday\n");
            break;
        case 3:
            printf("Thursday\n");
            break;
        case 4:
            printf("Friday\n");
            break;
        case 5:
            printf("Saturday\n");
            break;
        case 6:
            printf("Sunday\n");
            break;
    }
    }
    return 0;
}