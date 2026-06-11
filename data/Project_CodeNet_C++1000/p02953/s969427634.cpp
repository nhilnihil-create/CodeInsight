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
	vector<int> v;
	int a[n];
	for(int i=  0;i<n;i++)
	{
		cin >> a[i];
		v.pb(a[i]);
	}
	sort(all(v));
	for(int i = 0;i<n;i++)
	{
		if(abs(a[i] - v[i]) > 1)
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}