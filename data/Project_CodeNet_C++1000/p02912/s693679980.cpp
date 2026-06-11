#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
#define ll long long int
const double mx = 2e6 + 5 ;
void solve()
{
	ll n, m, x;
	ll ans = 0;
	cin>>n>>m;
	priority_queue <int> pq; 
	REP(i,n)
	{
		cin>>x;
		pq.push(x);
	}
	while(m>0)
	{
		x = pq.top();
		pq.pop();
		x/=2;
		pq.push(x);
		m--;	
	}
	while(!pq.empty())
	{
		ans+=pq.top();
		pq.pop();
	}
//	cout<<m<<" isleft\n";
	cout<<ans<<"\n";
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