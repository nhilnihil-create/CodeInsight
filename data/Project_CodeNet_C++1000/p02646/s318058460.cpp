#include<stdio.h>

int main(){
    long long i;
    long long a, b, v, w, t;
    long long s;

    scanf("%lld%lld%lld%lld%lld", &a, &v, &b, &w, &t);

    s = (a > b) ? (a - b):(b - a);

    for(i = 0;i < t;i++){
        s = s + w - v;
        if(s <= 0){
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}
