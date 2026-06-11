#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define si(x) (ll)((x).size())
#define pb push_back
#define F first
#define S second
#define rep(i,n) for(ll i=0;i<n;i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define per1(i,n) for(ll i=n;i>=1;i--)
#define all(x) (x).begin(), (x).end()
#define make_unique(x) (x).resize(unique(all(x))-(x).begin())
const ll inf = 1e18;
void file()
{

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);

#endif
}

void solve()
{
    ll n;
    cin >> n;
    std::vector<string> v(n);
    ll x[n];
    x[0] = 0;

    rep(i, n) cin >> v[i] >> x[i];
    string s;
    cin >> s;
    rep(i, n)
    {
    	if(i)
        x[i] += x[i-1];
    }
    if(v[0] == s)
    {
        cout << x[n-1]-x[0];
    }
    else
    rep(i, n)
    if(v[i] == s)
        cout << x[n-1]-x[i];

}

int main()
{



    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while(t--)
    {
        solve();
        // cout << endl;
    }


}


