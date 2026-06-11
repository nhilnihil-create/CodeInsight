#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n'
#define debug_arr(a , n) for(int i = 0 ; i < n ; i++)cout << a[i] << " "
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll> 
#define inf 1000000000
#define mod 1000000007

const int max_n = 1e5 + 9;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}
int main()
{
    int h1 , m1 , h2 , m2 , k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;

    h1 = h1 * 60 + m1 , h2 = h2 * 60 + m2;
    h2 -= k;

    cout << max(0 , h2 - h1) << endl;
    return 0;
}