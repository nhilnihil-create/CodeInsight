
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
	lli p,t=0,n,i;
	cin>>p>>n;
	lli a[n],b[n];
	rep(i,0,n){
		cin>>a[i];
	}
	lli ans=0;
	sort(a,a+n);
	rep(i,0,n-1){
		b[i]=a[i+1]-a[i];
	}
	b[n-1]=a[0]+p-a[n-1];
	sort(b,b+n);
	rep(i,0,n-1){
		ans+=b[i];
	}
	cout<<ans;
	return 0;
}