/* COMPETITIVE PROGRAMMING C++ TEMPLATE */

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <iomanip>

#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << "\n"

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;


void solve()
{
    //code here.
    ll n;
    cin >> n;
    ll count = 0;
    vector<ll>a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            count += (a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }

    }
    cout << count;

    


    

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    //cin >> T; // If only one test case then you can comment this line out.

    while (T--)
    {
        solve();

    }
    return 0;
}