#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, k;
    scanf("%d %d %d %d", &a, &b, &c, &k);
    int ans=0;

    if (k<a){
        ans = k;
    } else {
        ans+=a;
        k-=a;
    }

    if (k>=b){
        k-=b;
    } else {
        k=0;
    }

    if (k!=0){
        ans-=k;
        k-=c;
    }

    printf("%d\n", ans);


    return 0;
}
