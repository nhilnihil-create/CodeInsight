#include <stdio.h>

int main() {
    int mtr, sv;
     scanf("%d %d", &mtr, &sv);
     
     int bb= mtr%sv == 0;
     int aa= mtr/sv;
   
     bb ? printf("%d\n", aa) : printf("%d\n", aa+1);


    return 0;
}