#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);

    int first = n / 100;
    int second = (n / 10) % 10;
    int third = n % 10;

    while ( n > 0) {
        if ( first == 7) {
            puts("Yes");
            break;
        }
        else if ( second == 7) {
            puts("Yes");
            break;
        }
        else if ( third == 7) {
            puts("Yes");
            break;
        }
        else {
            puts("No");
            break;
        }
    } 
    return 0;
}