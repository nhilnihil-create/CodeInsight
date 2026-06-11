#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
//using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dh[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dw[8] = {1, -1, 0, 1, -1, 0, 1, -1};
  
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * (B / gcd(A, B));
}
using Graph = vector<vector<int>>;
Graph G;
  
/*------------------------------------------------------------------*/

int main(){
    ll n; cin >> n;
    vector<pair<ll,ll>> pos(n);
    rep(i, n){
        ll x, l; cin >> x >> l;
        pos[i].first = x + l;
        pos[i].second = x - l;
    }
    sort(pos.begin(), pos.end());

    int ans = 0;
    int X = -INFINITY;
    rep(i, n){
        if(X <= pos[i].second){
            ans++;
            X = pos[i].first;
        }
    }
    cout << ans << endl;
}