#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
using namespace std;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
//     tree_order_statistics_node_update>;
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
typedef long long int ll;
const ll N = 1e6;
// const ll m = 1e9 + 7;
// const ll inf= 1e14;
const ll mod = 998244353 ;
const ll INF = 1e16;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define pld pair<ld,ld>
#define pll pair<ll, ll>
#define pii pair<ll, ll>
#define ld long double
ll powm(ll a, ll b) { a = a%mod;ll res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
string a,b;
bool comp(ll i,ll j){
    return a[i]>a[j];
}
int main() {   
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);    
    #endif
    ll t = 1;
    // cin>>t; 
    while(t--){
        ll h1,m1,h2,m2,k;
        cin>>h1>>m1>>h2>>m2>>k;
        ll m = h1*60 + m1 - ((h2*60)+m2);
        m = abs(m)-k;
        cout<<m<<'\n';
    }
}              