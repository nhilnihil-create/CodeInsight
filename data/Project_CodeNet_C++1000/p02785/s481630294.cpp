#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v.at(i);
    std::sort(v.begin(), v.end(), std::greater<ll>());
    ll sum = 0;
    for(int i = k; i < n; i++) sum += v.at(i);
    cout << sum << endl;
    return 0;
}
