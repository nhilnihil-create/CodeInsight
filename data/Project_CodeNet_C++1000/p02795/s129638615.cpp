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
const int N = 2e5;
void solve()
{
    ll n, x, y, w, h, maxlevel = 0;
    cin >> w >> h >> n;

    cout << (n + max(w, h) - 1) / max(w, h);

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


