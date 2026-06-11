#include <stdio.h>

int main() {
	int Xz;
    long long int Zx[100004], ent = 1;
    scanf("%lld", &Xz);
    for (int i = 0; i < Xz; i++) {
        scanf("%lld", &Zx[i]);
    }
    for (int i = 0; i < Xz; i++) {
        if (Zx[i] == 0) {
            printf("0");
            return 0;
        }
    }
    for (int i = 0; i < Xz; i++) {
        if (Zx[i] <= (1000000000000000000 / ent)) {
            ent *= Zx[i];
        } else {
            printf("-1");
            return 0;
        }
    }
    printf("%lld", ent);
    
}
