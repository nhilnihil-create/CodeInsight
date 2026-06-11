
// Problem : E - Dist Max
// Contest : AtCoder - AtCoder Beginner Contest 178
// URL : https://atcoder.jp/contests/abc178/tasks/abc178_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
	lli n,p,b,i;
	cin>>n;
	lli a[n],c[n];
	for(i=0;i<n;i++){
		cin>>p>>b;
		a[i]=p+b;
		c[i]=p-b;
	}
	sort(a,a+n);
	sort(c,c+n);
	cout<<max(a[n-1]-a[0],c[n-1]-c[0]);
	return 0;
}