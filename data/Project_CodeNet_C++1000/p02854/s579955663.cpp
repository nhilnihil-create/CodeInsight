#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;


void solve(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    Vl A(n);
    ll sum = 0;
    rep(i, 0, n){
        cin >> A[i];
        sum += A[i];
    }

    ll ans = 1001001001001;
    ll l = 0;
    rep(i, 0, n-1){
        l += A[i];
        ll r = sum - l;
        ans = min(ans, abs(l - r));
    }

    cout << ans << endl;
}


int main() {
    solve();
}
