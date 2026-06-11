#include <stdio.h>
 
int main() {
 
    long x;
    char cr;
    scanf("%ld", &x);

    long name[14];
    for (long i = 0; i < 14; i++) {
        name[i] = -1;
    }

    name[0] = x-1;
    for (long i = 1; i < 14; i++) {
        name[i] += name[i-1]/26;
        name[i-1] %= 26;
    }
    
    for (long i = 13; i >= 0; i--) {
        if (name[i] == -1) {
            continue;
        }
        cr = 'a'+name[i];
        printf("%c", cr);
    }

    printf("\n");
 
  return 0;
}