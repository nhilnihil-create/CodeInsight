#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> pr(n);
    vector<ll> minus(n);
    vector<ll> add(n);
    rep(i,n){
        cin >> pr[i].first;
        pr[i].second = i+1;
        add[i] = pr[i].second + pr[i].first;
        minus[i] = pr[i].second - pr[i].first;
    }
    sort(minus.begin(),minus.end());
    ll cnt = 0;
    rep(i,n){
        ll key = add[i];
        auto upper_Iter = upper_bound(minus.begin(),minus.end(),key);
        auto lower_Iter = lower_bound(minus.begin(),minus.end(),key);
        cnt += upper_Iter - lower_Iter;
    }
    cout << cnt << endl;
    return 0;    
}