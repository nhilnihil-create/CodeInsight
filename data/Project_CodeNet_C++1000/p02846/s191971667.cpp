#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t1, t2, a1, a2, b1, b2;
    scanf("%lld%lld%lld%lld%lld%lld", &t1, &t2, &a1, &a2, &b1, &b2);
    if(a1*t1 + a2*t2 == b1*t1 + b2*t2) printf("infinity\n");
    else{
        if(a1*t1 + a2*t2 < b1*t1 + b2*t2){
            swap(a1, b1);
            swap(a2, b2);
        }
        if(a1*t1 < b1*t1){
            long long d1 = (a1*t1 + a2*t2) - (b1*t1 + b2*t2);
            long long d2 = b1*t1 - a1*t1;
            long long ans = d2/d1;
            bool add = 0;
            if(d2%d1 == 0) add = 1;
            printf("%lld\n", ans*2+1-add);
        }
        else printf("0\n");
    }
}