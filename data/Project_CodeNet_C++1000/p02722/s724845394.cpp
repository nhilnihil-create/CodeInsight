#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(all(x), val), x.end())
typedef long long ll;
typedef pair<int, int> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll MOD = 1000000007;
int INF = 1001001001;

void solve()
{
	ll n; cin >> n;
	if(n == 2)
	{
		cout << 1 <<endl;
		return;
	}
	else
	{
		ll ans = 2;
		for (ll i = 2; i * i <= n-1; i++)
		{
			if((n-1)%i == 0)
			{
				ans += 2;
				if((n-1)/i == i)ans--;
			}
		}
		for (ll i = 2; i * i <= n; i++)
		{
			if(n % i == 0)
			{
				ll k = n;
				while (k % i == 0)
				{
					k /= i;
				}
				if(k == 1)ans++;
				else if(k >= i && (k-1) % i == 0)ans++;
			}
		}
		cout << ans << endl;
		return;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
