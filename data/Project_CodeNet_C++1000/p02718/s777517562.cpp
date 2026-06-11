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
	int m,n;
	cin >> n >> m;
	int s=  0;
	vector<int> a(n);
	forn(i,n){
		cin>>a[i];
		s+=a[i];
	}
	sort(rall(a));
	double mn = (double)s / (double)(m * 4);
	forn(i,m)
	{
		if((double)a[i] < mn)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}