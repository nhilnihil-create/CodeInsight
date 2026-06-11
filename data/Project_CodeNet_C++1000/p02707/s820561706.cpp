#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> ans(n+1, 0);
    rep(i, 0, n-1){
        ll a;
        cin >> a;
        ans[a]++;
    }
    rep(i, 1, n+1) cout << ans[i] << endl;
    return 0;
}