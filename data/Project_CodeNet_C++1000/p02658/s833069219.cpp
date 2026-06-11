#include<stdio.h>

int main() {

    int berapaKali;
    long long a1[100001];
    long long a2 = 1;
    long long max = 1000000000000000000;

    scanf("%d", &berapaKali);

    for(int j=0;j<berapaKali;j++){
        scanf("%lld", &a1[j]);
        if(a1[j]==0){
            printf("0");
            return 0;
        }
    }

    for (int i = 0; i < berapaKali; i++) {
        if (a1[i] > max) {
            printf("-1");
            return 0;
        }
        a2 *= a1[i];
        max /= a1[i];
    }

    printf("%lld", a2);

    return 0;

}