#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

using Graph = vector<vector<int>>;

int main() {
    int n;
    cin >> n;
    Graph G(1000*n+n);
    vector<int> h(1000*n+n, 0);
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i, n){
        rep(j, n-1){
            cin >> a[i][j]; 
            a[i][j]--;
            if(j){
                int mi1 = min(a[i][j-1], i);
                int ma1 = max(a[i][j-1], i);
                int mi2 = min(a[i][j], i);
                int ma2 = max(a[i][j], i);
                G[1000*mi1+ma1].push_back(1000*mi2+ma2);
                h[1000*mi2+ma2]++;
            }
        }
    }
    map<ll, ll> mp;
    stack<int> st;
    rep(i, n){
        rep(j, n-1){
            int mi = min(a[i][j], i);
            int ma = max(a[i][j], i);
            if(h[1000*mi+ma] == 0 && !mp[1000*mi+ma]){
                st.push(1000*mi+ma);
                mp[1000*mi+ma]++;
            }
        }
    }
    vector<int> ans;
    while(st.size()){
        int i = st.top(); st.pop();
        ans.push_back(i);
        for(auto& j : G[i]){
            h[j]--;
            if(h[j] == 0)st.push(j);
        }
    }
    if(ans.size() != n*(n-1)/2)cout << -1 << endl;
    else{
        vector<int> ok(1000*n+n, 1);
        rep(i, ans.size()){
            for(auto& j : G[ans[i]]){
                chmax(ok[j], ok[ans[i]]+1);
            }
        }
        cout << *max_element(all(ok)) << endl;
    }
}
