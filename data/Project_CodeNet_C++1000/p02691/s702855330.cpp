#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
using Graph = vector<vector<int>>;
Graph G;
int main(){
    vector<pair<ll,ll>> vec(200010);
    rep(i, 200010){
        vec[i].first = 0, vec[i].second = 0;
    }
    int n; cin >> n;
    rep(i, n){
        ll a; cin >> a;
        if(i + a + 1 <= 200000) vec[(i + 1) + a].first++;
        if(i - a >= 0) vec[(i + 1) - a].second++;
    }
    ll ans = 0;
    rep(i, 200010){
        ans += vec[i].first * vec[i].second;
    }
    cout << ans << endl;
}