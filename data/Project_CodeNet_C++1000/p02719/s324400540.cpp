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
	ll n,k;
	cin >> n >> k;
	if(k==n){
		cout <<0;
		return 0;
	}
	if(k > n){
		cout << min(n,abs(k-n));
		return 0;
	}
	ll moves = n / k;
	n  = n - moves * k;
	if(n==0){
		cout << n;
		return 0;
	}
	cout << min(n,abs(n-k));
	return 0;
}