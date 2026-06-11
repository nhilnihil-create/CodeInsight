
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
	cio;
	lli n,m,k,ans=0,i;
	double sum=0,dd;
	cin>>n>>m;
	dd=4*m;
	lli a[n];
	rep(i,0,n){
		cin>>a[i];
		sum+=a[i];
	}
	dd=sum/dd;
	k=ceil(dd);
	rep(i,0,n){
		if(a[i]>=k)
		ans++;
	}
	if(ans>=m) cout<<"Yes";
	else cout<<"No";
	return 0;
}