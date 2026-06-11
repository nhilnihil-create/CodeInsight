//Solution By SlavicG
#include "bits/stdc++.h"
using namespace std;
 
#define ll                          long long
 
#define forn(i,n)                   for(int i=0;i<n;i++)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend()
	
#define pb                          push_back
#define sz(a)                       (int)a.size()
 
#define   endl                       "\n"
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int  main()
{
	map<string,string> m;
	string s;
	m["ARC"] = "ABC";
	m["ABC"] = "ARC";
	cin >> s;
	cout << m[s];
}