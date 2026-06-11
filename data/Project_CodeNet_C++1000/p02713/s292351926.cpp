#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){ return b ? gcd(b,a%b) : a; }

void solve(long long K){
    ll ans = 0;
    for(ll a = 1; a <= K; ++a){
        for(ll b = 1; b <= K; ++b){
            ll ab = gcd(a, b);
            for(ll c = 1; c <= K; ++c){
                ans += gcd(ab, c);
            }
        }
    }
    cout << ans << endl;
    return;
}

int main(){
    long long K;
    scanf("%lld",&K);
    solve(K);
    return 0;
}
