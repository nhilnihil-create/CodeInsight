#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5+5;

const int mod = 1e9+7;

int n;
int a[N];
int b[N];

int main(){
    scanf("%d " , &n);
    long long ans = 0;
    for(int i = 1; i <= n + 1; i++){
        scanf("%d" , &a[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf(" %d" , &b[i]);
        int dec = min(b[i] , a[i]);
        b[i] -= dec;
        a[i] -= dec;
        ans += dec;
        dec = min(b[i] , a[i + 1]);
        ans += dec;
        a[i + 1] -= dec;
    }
    printf("%lld\n" , ans);
}
