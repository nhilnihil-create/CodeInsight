#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    vector<vector<int>> ab(m);
    rep(i,n){
        int x,y;
        cin >> x >> y;
        if(x > m) continue;
        x--;
        ab[x].push_back(y);
    }
    priority_queue<int> q;
    ll ans = 0;
    rep(i,m){
        for(auto x : ab[i]){
            q.push(x);
        }
        if(q.empty()) continue;
        ans += q.top();
        q.pop();
    }
    cout << ans  << endl;

    cout << endl;
    return 0;
}
