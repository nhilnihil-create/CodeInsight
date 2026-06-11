#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0;
    ll itr = 0;
    rep(i, 0, n-1){
        if(i % 2) itr++;
        ans += a[itr];
    }
    cout << ans << endl;
    return 0;
}