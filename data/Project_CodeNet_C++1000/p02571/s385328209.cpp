#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

void solve(){
    string s, t;
    cin >> s >> t;
    int ans = INF;
    int n = s.size(), m = t.size();
    for (int i = 0; i <= n - m; ++i){
        int tmp = 0;
        for (int j = 0; j < m; ++j){
            if (s[i+j] != t[j])tmp++;
        }
        ans = min(tmp, ans);
    }
    cout << ans << '\n';
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}

