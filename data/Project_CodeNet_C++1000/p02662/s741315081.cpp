#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define getbit(n, i) (((n) & (1LL << (i))) != 0) 
#define setbit0(n, i) ((n) & (~(1LL << (i)))) 
#define setbit1(n, i) ((n) | (1LL << (i))) 
#define togglebit(n, i) ((n) ^ (1LL << (i))) 
#define lastone(n) ((n) & (-(n))) 
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first << gap << p.second << ')';
}

template <class T>
void read(T &x) {
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        ;
    for (x = 0; c <= '9' && c >= '0'; c = getchar()) x = x * 10 + (c & 15);
}
#define ll long long
#define lll __int128_t
#define pb push_back
#define mp make_pair
typedef pair < int,int> ii;
typedef vector<ii> vii;
typedef vector<ll>vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;
ll dp[3001][3001];
#define mod 998244353
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
         // Base Case 
         if (a == 0) 
         { 
             *x = 0, *y = 1; 
             return b; 
         } 
   
         ll x1, y1; // To store results of recursive call 
         ll gcd = gcdExtended(b%a, a, &x1, &y1); 
   
   
         *x = y1 - (b/a) * x1; 
         *y = x1; 
   
         return gcd; 
} 
 ll modInverse(ll a, ll m) 
{ 
         ll x, y; 
         ll g = gcdExtended(a, m, &x, &y); 
   
        ll res = (x%m + m) % m; 
         return res; 
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i, j, k, l, n, m;
    cin >> n >> m;
    ll data[n + 1];
    for (i = 1; i <= n;i++){
        cin >> data[i];
    }
    ll precalc[n + 1];
    precalc[0] = 1;
    for (i = 1; i <= n;i++){
        precalc[i] = (precalc[i - 1] * 2) % mod;
    }
    dp[0][0] = precalc[n];
    for (i = 1; i <= n;i++){
        for (j = 0; j <= m;j++){
            dp[i][j] = dp[i - 1][j];
            if(j>=data[i]){
                (dp[i][j] += (dp[i - 1][j - data[i]] * modInverse(2, mod)) % mod) %= mod;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}