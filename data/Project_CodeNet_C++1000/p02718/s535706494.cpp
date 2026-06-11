#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m;
    cin >> n >> m;
    ll cnt = 0;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    for(auto e : a) if(e * 4 * m >= sum) cnt++;
    if(cnt >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}