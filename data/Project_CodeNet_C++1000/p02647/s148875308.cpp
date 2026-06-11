#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
#define ll long long int
const int mx = 200010;
int a[mx], b[mx];
void solve()
{
	int n, k;
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	REP(T, k)
	{
		memset(b, 0, sizeof(b));
		for(int i=1; i<=n; i++)
		{
			int l = max(1, i-a[i]);
			int r = min(n+1, i+a[i]+1);
			b[l]++;
			b[r]--;
		}
		bool pos = true;
		for(int i=1; i<=n; i++)
		{
			b[i]+=b[i-1];
			if(b[i]<n)
			{
				pos = false;
			}
		}
		swap(a,b);
		if(pos)
			break;
	}
	for(int i=1; i<=n; i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}