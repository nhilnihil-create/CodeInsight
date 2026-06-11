//Solution By SlavicG
#include <bits/stdc++.h>
using namespace std;
 
#define ll                          long long
 
#define forn(i,n)                   for(int i=0;i<n;i++)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend()
	
#define pb                          push_back
#define sz(a)                       (int)a.size()
 
#define   endl                       "\n"
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

int32_t  main()
{
	int n;
	cin >> n;
	map<string,int> m;
	for(int i = 0;i<n;i++)
	{
		string s;
		cin >> s;
		sort(all(s));
		m[s]++;
	}
	int ans = 0;
	for(auto x : m)
	{
		int k = x.second;
		ans += (k  *(k-1)) / 2;
 	}
	cout << ans << endl;
}