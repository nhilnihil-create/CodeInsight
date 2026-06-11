#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repp(i, m, n) for(int i = m; i < (int)n; i++)
#define reps(i, n) for(int i = 1; i <= (int)n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pai;
typedef pair<ll,ll> pal;



int main()
{
	int n, m;
	while(cin >> n  && n!=0)
	{
		cin >> m;
		ll h[1510]={}, w[1510]={};
		ll a[2000010]={}, b[2000010]={};
		reps(i, n) cin >> h[i];
		reps(i, n) h[i]+=h[i-1];
		reps(i, m) cin >> w[i];
		reps(i, m) w[i]+=w[i-1];
		
		
		rep(i, n+1)rep(j, n+1) a[(int)abs(h[i]-h[j])]+=1;
		
		rep(i, m+1)rep(j, m+1) b[(int)abs(w[i]-w[j])]+=1;
		
		
		
		ll ans=0;
		reps(i, 2000000) ans+=a[i]*b[i]/4;
		
		cout << ans << endl;
	}
	return 0;
}