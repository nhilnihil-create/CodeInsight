#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = b - 1; i >= a; i--)
typedef long long ll;

int main(){
    ll M; cin >> M;
    vector<ll> d(M), c(M);
    rep(i, 0, M) cin >> d[i] >> c[i];

    ll sum = 0;
    ll ans = 0;
    rep(i, 0, M) ans += c[i];
    rep(i, 0, M){
        sum += d[i] * c[i];
    }
    if(sum % 9 == 0) ans--;
    cout << ans - 1 + sum / 9 << endl;
}