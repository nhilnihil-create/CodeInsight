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
	//cin >> t;
	while (t--)
	{
		int h, w, k;
		cin >> h >> w >> k;

		string s[h];

		for (int i = 0; i < h; i++)
			cin >> s[i];

		int powh = pow(2, h);

		int poww = pow(2, w);
		int ans = 0;
		for (int i = 0; i < powh; i++)
		{
			for (int j = 0; j < poww; j++)
			{

				string temp[h];
				for (int k = 0; k < h; k++)
					temp[k] = s[k];
			//	for (int k = 0; k < h; k++)
			//		cout<<temp[k]<<endl;
				
				int ii = i, jj = j;
				int x = 0;
				while (ii)
				{

					int rem = ii % 2;
					if (rem == 1)
					{
						for (int col = 0; col < w; col++)
						{
							temp[x][col] = '/';
						}
					}
					x++;
					ii /= 2;
				}
				x = 0;
				while (jj)
				{
					
					int rem = jj % 2;
					if (rem == 1)
					{
					//	cout<<"hey";
						for (int row = 0; row < h; row++)
						{
							temp[row][x] = '/';
						}
					}
					x++;
					jj /= 2;
				}
				int cnt = 0;
				for (int row = 0; row < h; row++)
				{
					for (int col = 0; col < w; col++)
					{
						if (temp[row][col] == '#')
							cnt++;
					}
				}

				if (cnt == k)
					ans++;

			//	deb(ans);
			}
		}

		cout<<ans<<endl;
	}
}