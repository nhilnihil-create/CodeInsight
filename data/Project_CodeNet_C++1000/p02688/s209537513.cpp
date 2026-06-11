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
const int N = 1e3;
bool snuke[N];
int  main()
{
	int n,k;
	cin >> n >> k;
	int d[k];
	forn(i,k)
	{
		cin >> d[i];
		int a[d[i]];
		forn(j,d[i])
		{
			cin >> a[j];
			a[j]--;
			snuke[a[j]] = true;
		}
	}
	int ret=  0;
	forn(i,n)
		if(!snuke[i])
			ret++;
	cout << ret << endl;
}