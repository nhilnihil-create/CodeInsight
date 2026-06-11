#pragma GCC optimize ("Ofast","unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define F first
#define S second
#define setpre(a) cout.precision(a),cout<<fixed;
#define ALL(a) a.begin(),a.end()
#define MEM(a,b) memset(a,b,sizeof a)
#define Tie ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

ll n, ans;
vector<int> v[200100];
pii a[200100];

void dfs(ll a, ll f) {
    for(int i : v[a]) {
        if(i == f) continue;
        if(i < a) {
            dfs(i, a);
            ans += i * (a - i);
        } else if(i > a) {
            dfs(i, a);
            ans += (i - a) * (n - i + 1);
        }
    }
}

int main() {Tie
    cin >> n;
    for(int i = 1, x, y; i < n; i++)
        cin >> x >> y, v[x].pb(y), v[y].pb(x);

    dfs(1, 0);
    cout << ans + n << '\n';
}
