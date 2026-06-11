//Solution By SlavicG
#include "bits/stdc++.h"
using namespace std;

 
#define forn(i,n)                   for(int i=0;i<n;i++)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend()
	
#define pb                          push_back
#define sz(a)                       (int)a.size()
 
#define   endl                       "\n"
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int  main()
{
	int t;
	cin >> t;
	set<string> s;
	while(t--)
	{
		string a;
		cin >> a;
		s.insert(a);
	}
	cout << sz(s);
}