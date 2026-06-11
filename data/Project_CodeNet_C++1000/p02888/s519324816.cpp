
// Problem : D - Triangles
// Contest : AtCoder - AtCoder Beginner Contest 143
// URL : https://atcoder.jp/contests/abc143/tasks/abc143_d
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
using namespace std;
bool tri(lli a,lli b,lli c){
	if(a+b>c && b+c>a && c+a>b)
	return true;
	return false;
}
int main()
{
	lli k,j,a,n,i,ans=0;
	cio;
	cin>>n;
	vector<lli>v;
	vector<lli>::iterator it;
	for(i=0;i<n;i++){
		cin>>a;
		v.pb(a);
	}
	sort(v.begin(),v.end());
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			it=lower_bound(v.begin(),v.end(),v[i]+v[j]);
			a=it-v.begin();
			ans+=a-j-1;
		}
	}
	cout<<ans;
	return 0;
}