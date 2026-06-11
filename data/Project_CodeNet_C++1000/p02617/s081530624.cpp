#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef vector <ll> vll;
typedef pair <ll, ll> pll;
#define pb push_back
#define mp make_pair
#define MAX 1000000
#define mod 1000000007
#define all(_) _.begin(), _.end()
#define F first
#define S second
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll n, i, ans = 0, u, v;
    cin >> n;
    for(i = 1; i <= n; i++)
        ans += i * (n - i + 1);
    for(i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        if(u > v)
            swap(u, v);
        ans -= u * (n - v + 1);
    }
    cout << ans << endl;
    return 0;
}