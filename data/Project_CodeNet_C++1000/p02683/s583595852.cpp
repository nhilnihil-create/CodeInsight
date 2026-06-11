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
const ll N = 1e5+5; 
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


int n, m, x, c[15], a[15][15];

void solve()
{
    cin >> n >> m >> x;
    for (int i=0; i<n; ++i) {
    	cin >> c[i];
    	for (int j=0; j<m; ++j) {
    		cin >> a[i][j];
    	}
    }
    ll ans=INF;
    for (int mask=0; mask<(1<<n); mask++) {
    	ll sum=0, cost=0;
    	ll xd[m]; fill(xd,xd+m,0);
    	for (int i=0; i<n; ++i) {
    		if (1&(mask>>i)) {
    			cost += c[i];
    			for (int j=0; j<m; j++) xd[j] += a[i][j];
    		}
    	}
    	bool found=true;
    	for (int i=0; i<m; ++i) if (xd[i]<x) found=false;
    	if (found) ans=min(ans,cost);
    }

    nout(ans==INF?-1:ans);
    
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