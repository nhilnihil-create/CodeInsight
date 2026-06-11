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
	int k ,a ,b;
	cin >> k >> a >> b;
	for(int i =  a;i <= b;i++)
		if(i % k==0)
		{
			cout << "OK\n";
			return 0;
		}
	cout << "NG\n";
}