/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @Author: Tard1grad3                                                         *
 * @Last modified time: Sunday, September 20th 2020, 07:40:15 pm (UTC+06:00)   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <bits/stdc++.h>
using namespace std;
#define IC ios_base::sync_with_stdio(false); cin.tie(NULL);
#define f(i, a, b) for(int i=a; i<b; i++)
#define ff(i, a, b) for(int i=a-1; i>=b; i--)
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mp make_pair
#define sz 1005
#define mod 998244353
#define line "\n"
#define ALL(x) x.begin(), x.end()
#define F first
#define S second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<char, int> mci;
const double PI = acos(-1);

// int a[sz];
// string s;
// si st;
// vector<string> vs;
// vector<char> vc;
// mci mm;


void solve()
{
    ll k, a, b, c, d, n, m=0, cnt=0, flg=0, ans=0, pos=0, sum=0, mx=INT_MIN, mn=INT_MAX;
    cin >> a >> b >> c >> d;
    cout << max(max(max(a*c, a*d), b*c), b*d);
}

int main()
{
    int T=1, k=1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}
