#include <bits/stdc++.h>
#define INF 1e18
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define MAX 1000
#define ll long long
#define P pair<int,int>
using namespace std;
const int mod = 1000000007;
//char c[MAX][MAX];
int step[MAX][MAX];
int H,W,N; 
int vy[4] ={1,-1,0,0}, vx[4] = {0,0,-1,1}; //up,down,left,right 

signed main(){
    ll n; cin >> n;
    vector<pair <ll,ll>> x;
    rep(i,n) {
        pair<ll,ll> p;
        ll a,b; cin >> a >> b;
        p.first = a + b; p.second = a - b;
        x.push_back(p);
        }
    sort(x.begin(),x.end());
    ll now = mod * -1; ll ans=0;
    rep(i,n){
        if(now <= x[i].second){
            now = x[i].first;
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}