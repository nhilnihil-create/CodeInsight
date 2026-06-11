
// Problem : B - TAKOYAKI FESTIVAL 2019
// Contest : AtCoder - AtCoder Beginner Contest 143
// URL : https://atcoder.jp/contests/abc143/tasks/abc143_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include<set>
#define lli long long int
#define pb push_back;
#define rep(i,a,n) for(i=a;i<n;i++)
#define all(v) (v.begin(),v.end())
#define ppb pop_back
#define vsz v.size()
using namespace std;
int main()
{
	lli n,i,j,ans=0;
	cin>>n;
	lli a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			ans+=a[i]*a[j];
		}
		ans-=a[i]*a[i];
	}
	cout<<ans/2;
	
	return 0;
}