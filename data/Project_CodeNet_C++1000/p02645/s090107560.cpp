#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forr(i, n) for(int i = 0;i < (int)n; i++)
#define deb(x) cout<<#x<<" " <<x<<"\n";
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define mp make_pair
#define test int t;cin >> t;while(t--)
#define endl "\n"
const int INF = 2e9;
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	forr(i,s.length()) {
		if(i==3) break;
		cout<<s[i];
	}
	return 0;
}
