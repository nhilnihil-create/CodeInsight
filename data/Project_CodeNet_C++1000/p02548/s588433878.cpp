// author : ayush_nishad
// Road to Expert since : 30 Aug 2020
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define in insert
#define F first
#define S second
#define mod 1000000007
#define endl '\n'
#define all(x)  x.begin(),x.end()
#define w(x) int x;cin>>x; while(x-->0)
#define memset(a,b) memset(a,b,sizeof(a))
#define debug(x) cout << "[ " << #x  << " : " << x << " ]" << endl;

void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

}
/*
think fast
think simple
*/
void mysol()
{
	int v; cin >> v;
	int ans = 0;
	for (int i = 1; i < v; i++)
		for (int j = 1; i * j < v; j++)
			ans++;
	cout << ans << endl;
}

int32_t main()
{
	fast();
	// w(t)
	{
		mysol();
	}
	//cerr << sizeof(dp)*(1e-6) << " megabytes\n";
	return 0;
}
