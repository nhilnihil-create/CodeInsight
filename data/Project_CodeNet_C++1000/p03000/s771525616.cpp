/**
 * @author: Mackenzie
**/
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n,x;
    cin>>n>>x;
    ll d=0,ans=0;
    forn(i,n){
        int l;
        cin>>l;
        d=(d+l);
        if(d<=x)ans++;
    }
    cout<<ans+1<<endl;
    return 0;
}
