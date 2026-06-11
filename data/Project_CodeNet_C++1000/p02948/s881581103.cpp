#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
int main(){
    ll n, m; 
    cin >> n >> m;
    vector<vector<ll> > v(110000);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    ll ans = 0;
    priority_queue<ll> p;
    REP(i,1,m+1){
        rep(j, v[i].size())p.push(v[i][j]);
        if(!p.empty()){
            ans += p.top();
            p.pop();
        }
    }
    cout << ans << endl;

    return 0;
}