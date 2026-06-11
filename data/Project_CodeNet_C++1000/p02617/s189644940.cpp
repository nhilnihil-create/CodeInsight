#include <bits/stdc++.h>

#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 100;
//#define int long long
const int INF = 1e9;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a, b;
    ll ans = 0LL;
    for (int i = 0; i < n-1; i++){
    	cin >> a >> b;
    	if (a > b) swap(a, b);
    	
    	ans -= (ll)a * (ll)(n - b + 1);
    }

    for (int i = 1; i <= n; i++){
    	ans += (ll)i * (ll)(n - i + 1);
    }

    cout << ans << '\n';
    return 0;
}
