
#include<bits/stdc++.h>
#include<set>
#define lli long long int
#define pb push_back
#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,a,n) for(i=a;i<n;i++)
#define all(v) (v.begin(),v.end())
#define ppb pop_back
#define vsz v.size()
#define pi 3.141592653589793238
using namespace std;
int main()
{
	lli t,n,k,i;
	cin>>n>>k;
	vector<lli>v;
	n--;
	t=n;
	v.pb(k);
	for(i=n;i>=1;i--){
		v.pb(k-i);
	}
	for(i=t;i>=1;i--) v.pb(k+i);
	sort all(v);
	for(i=0;i<v.size();i++) cout<<v[i]<<" ";	
	return 0;
}