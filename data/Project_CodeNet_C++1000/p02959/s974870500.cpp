#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n;
int a[N];
int b[N];

int main(){
    scanf("%d " , &n);
    for(int i = 1; i <= n + 1; i++){
        scanf("%d" , &a[i]);
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        scanf(" %d" , &b[i]);

        long long dec = min(b[i] , a[i]);
        ans += dec;
        b[i] -= dec;
        dec = min(b[i] , a[i + 1]);
        a[i + 1] -= dec;
        ans += dec;
    }
    printf("%lld\n" , ans);
}
