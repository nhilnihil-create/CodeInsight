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
    ll n, i;
    cin >> n;
    for(i = 0; (1 << i) <= n; i++)
    {
        if((1 << i) == n)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(i = 2; i < n + n % 2; i += 2)
    {
        cout << "1 " << i << endl;
        cout << "1 " << n + i + 1 << endl;
        cout << i << ' ' << i + 1 << endl;
        cout << n + i + 1 << ' ' << n + i << endl;
    }
    cout << "3 " << n + 1 << endl;
    if(n % 2 == 0)
    {
        for(i = 2; i < n; i++)
        {
            ll val = (i ^ 1) ^ n;
            if(val < n)
            {
                cout << n << ' ' << (i % 2 == 0 ? i : n + i) << endl;
                cout << 2 * n << ' ' << (val % 2 == 0 ? val : n + val) << endl;
                break;
            }
        }
    }
    return 0;
}