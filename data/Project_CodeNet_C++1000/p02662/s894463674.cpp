#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define mod 998244353
#define xx first
#define yy second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define N 3010

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;/// find_by_order(x)(x+1th) , order_of_key() (strictly less)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());




int n;
ll a[N];
ll dp[N][N];
ll tmp[N][N];
ll s;

ll mul(ll x, ll y){
    return (x * y) % mod;
}

ll power(ll x, ll y){
    if(y == 0)return 1;
    ll pola = power(x, y/2);
    pola = mul(pola, pola);
    if(y%2)pola = mul(pola, x);
    return pola;
}

int main()
{

    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s;
    ll sum = 0;
    ff(i,1,n){
        cin >> a[i];
        sum += a[i];
    }
    ll inv2 = power(2, mod - 2);
    dp[0][0] = power(2, n);
    ll sta = power(2, n - 1);
    ff(i,1,n){
        ff(j,0,s){
            bool da = 0;
            if(j - a[i] >= 0)da = 1;
            if(da){
                if(j - a[i] > 0)dp[i][j] = (inv2 * dp[i - 1][j - a[i]])%mod;
                else dp[i][j] = sta;
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j])%mod;
        }
    }
    cout << dp[n][s] << "\n";
    return 0;
}
