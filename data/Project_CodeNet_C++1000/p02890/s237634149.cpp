#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n; cin >> n;
    map<ll,ll> mp;
    rep(i,n){
        ll a; cin >> a;
        mp[a]++;
    }
    vector<ll> data;
    for(auto p : mp){
        data.push_back(p.second);
    }
    sort(all(data));
    ll d = data.size();

    vector<ll> ans(n+1,0);
    loop(i,1,n+1){
        ll id = lower_bound(all(data),i) - data.begin();
        ans[i] += (d - id);
        ans[i] += ans[i-1];
    } // i+1回操作する
    loop(i,1,n+1){
        ll low = 0, high = n+1;
        while(high-low > 1){
            ll mid = (high+low)>>1;
            if(ans[mid] >= i*mid) low = mid;
            else high = mid;
        }
        cout << low << endl;
    }
}