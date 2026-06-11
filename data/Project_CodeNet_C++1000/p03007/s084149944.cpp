#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll max_sum = a[n-1];
    ll min_sum = a[0];
    vector<pair<ll, ll>> ans;
    rep(i, n-2) {
        if ( a[i+1] >= 0 ) {
            ans.emplace_back(min_sum, a[i+1]);
            min_sum -= a[i+1];
        }
        else {
            ans.emplace_back(max_sum, a[i+1]);
            max_sum -= a[i+1];
        }
    }
    ans.emplace_back(max_sum, min_sum);
    cout << max_sum - min_sum << endl;
    rep(i, n-1) printf("%lld %lld\n", ans[i].first, ans[i].second);
    return 0;
}
