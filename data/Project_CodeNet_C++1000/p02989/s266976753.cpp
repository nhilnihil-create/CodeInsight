#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll arc=0,abc=0,m,n,k,cnt=0;
	cin>>n;
	ll a[n];
	REP(i,0,n-1)
		cin>>a[i];
	sort(a,a+n);
	cout<<a[n/2]-a[(n/2)-1];
}