#include<bits/stdc++.h>
//#include<tr1/unordered_map>
#pragma GCC optimize ("Ofast")
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forn(i, n) for(int i=0; i<int(n); i++)
#define Forn(i, n) for(int i=1; i<=int(n); i++)

using namespace std;

int n, k;
ll h[310];

ll dp[310][310][310];
bool memo[310][310][310];
ll f(int x, int y, int z)
{
    if(x == n+1) return 0;
    if(memo[x][y][z]) return dp[x][y][z];
    ll ans = f(x+1, x, z) + max(0LL, h[x] - h[y]);
    if(z>0) ans = min(ans, f(x+1, y, z-1));
    memo[x][y][z] = 1;
    dp[x][y][z] = ans;
    return ans;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n >> k;
    Forn(i, n) cin >> h[i];
    cout << f(1, 0, k) << endl;
}
