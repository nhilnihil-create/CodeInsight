//Solution By SlavicG
#include <bits/stdc++.h>
using namespace std;
 
#define ll                          long long
 
#define forn(i,n)                   for(int i=0;i<n;i++)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend()
	
#define pb                          push_back
#define sz(a)                       (int)a.size()
#define mp                          make_pair
 
#define   endl                       "\n"
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int  main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1; i <=n;i++)
	{
		if(i>=1&&i<=9)
			cnt++;
		if(i>=100&&i<=999)
			cnt++;
		if(i>=10000&&i<=99999)
			cnt++;
	}
	cout << cnt << endl;
}