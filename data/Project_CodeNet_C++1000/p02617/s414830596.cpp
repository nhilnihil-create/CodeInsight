#include <bits/stdc++.h>
#define PCI(X) __builtin_popcount((X))
#define PCL(X) __builtin_popcountll((X))
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (ll I = (A); I < (B); ++I)
#define REPC(I, A, B, C) for (ll I = (A); I < (B); I = I + (C))
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VB vector<bool>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

#define VVI vector<vector<int> >
#define VVPII vector<vector<pair<int,int> > >

typedef long long ll;
using namespace std;

// link: https://atcoder.jp/contests/abc173/tasks/abc173_f

void boost()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << fixed << setprecision(10);
}


void solve()
{
    ll n;
    cin >> n;
    
    ll ans = 0;
    REPP(i, 1, n + 1) ans += i*(n - i + 1);

    ll a, b, c, d;
    REP(i, n - 1) {
        cin >> a >> b;
        c = min(a, b);
        d = max(a, b);
        ans -= c*(n - d + 1);
    }

    cout << ans << "\n";
}

int main()
{
    boost();
    int T;
    T = 1;
    
    while (T--) {
    	solve();
    }
}
