// ABC166E.cpp 

#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>rs(n);
    vector<ll>ls(n);
    rep(i, n) {
        cin >> a[i];
        if (i + a[i] < n) rs[i + a[i]]++;
        if (i - a[i] >= 0) ls[i - a[i]]++;
    }
    ll ans = 0;
    rep(i, n) {
        ans += (rs[i] * ls[i]);
    }
    cout << ans;
}

