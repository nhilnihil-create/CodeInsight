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
    ll m, d, ans = 0;
    cin >> m >> d;
    for(ll i = 1; i <= m; i++)
    {
        for(ll j = 1; j <= d; j++)
        {
            if(((j / 10) % 10) * (j % 10) == i && j % 10 >= 2 && (j / 10) % 10 >= 2)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}