#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005];
ll SUM = 0;
ll basis[60];
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%lld",&a[i]);
        SUM ^= a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++){
        a[i] &= (~SUM);
        for (int j = 59; j >= 0; j--){
            if ((a[i] & (1ll<<j)) == 0) continue;
            if (basis[j] == 0){
                basis[j] = a[i];
                break;
            }
            a[i] ^= basis[j];
        }
    }
    for (int i = 59; i >= 0; i--){
        if (basis[i] != 0){
            if ((ans & (1ll<<i)) == 0){
                ans ^= basis[i];
            }
        }
    }
    ans <<= 1;
    ans += SUM;
    printf("%lld",ans);
}
