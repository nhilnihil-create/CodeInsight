#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define endl '\n'
#define boost                    \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0);
#define mod 1000000007
#define inf 1e18
#define pf push_front
#define pob pop_back
#define pof pop_front
#define deb(x) cout << #x << " " << x << endl;
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define deb3(x, y, z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;
#define file                          \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

int32_t main()
{
	// boost
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			//sum += a[i];
		}
		sort(a, a + n, greater<int>());
		int ans = a[0];
		int ctr = 1;
		for (int i = 1; i < n; i++)
		{
			if (ctr >= n - 1)
				break;
			ans += a[i];
			ctr++;
			if (ctr >= n - 1)
				break;
			ans += a[i];
			ctr++;
		}

		cout<<ans<<endl;
	}
}