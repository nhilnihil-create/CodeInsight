#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    rep(i, 0, n) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for(auto e : a) cout << e.second << endl;
    return 0;
}