#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
 
/*------------------------------------------------------------------*/
 
int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> a_sum(n + 1);
    a_sum[0] = 0;
    _rep(i, 1, n + 1) a_sum[i] = a_sum[i - 1] + a[i - 1];
    ll ans_min = INFINITY;
    rep(i, n + 1){
        ans_min = min(ans_min, abs(a_sum[i] - (a_sum[n] - a_sum[i])));
    }
    cout << ans_min << endl;
}