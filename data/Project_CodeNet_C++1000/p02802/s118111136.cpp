#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 500005
#define INF INT_MAX

#define PI   3.14159265358979323846264338327950

#define PB push_back
#define PF push_front
#define F first
#define S second

#define fixx(n) fixed << setprecision(n)

#define ll 	 long long

#define mod  1000000007

map<int, bool> mp;
map<int, int> mp1;
int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	int p[m+6];
	string s[m+6];
	ll ans = 0;
	int a1 = 0;
	for(int i = 0; i < m; i ++){
		cin >> p[i] >> s[i];
		if(s[i] == "AC" && !mp[p[i]] ){
			a1 ++;
			ans += mp1[p[i]];
			mp[p[i]] = true;
		}
		if(!mp[p[i]] && s[i] == "WA"){
			mp1[p[i]] ++;
		}
	}
	cout << a1 << " " << ans;
	return 0;
}