#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define nout(ans) cout << (ans) << "\n"
#define sout(ans) cout << (ans) << " "
using namespace std;

const double pi = 3.14159265359;
const ll INF = 1e12;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5; 
/*
Decimal Places: cout << fixed << setprecision(n) << ans << endl
*/

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

ll raise(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


ll n, a[N];

void solve()
{
    cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i];
    int ans=0, cnt=1;
    for (int i=1; i<n; ++i) {
        if (a[i]<=a[i-1]) cnt++;
        else{
            ans=max(ans,cnt); cnt=1;
        }
    }ans=max(ans,cnt);
    nout(ans-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++)
    {
        solve();
    }
    return 0;
}           