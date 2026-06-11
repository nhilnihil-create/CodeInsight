
// Problem : D - Lunlun Number
// Contest : AtCoder - AtCoder Beginner Contest 161
// URL : https://atcoder.jp/contests/abc161/tasks/abc161_d
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
	cio;
	lli t,k,n=0,i;
	cin>>k;
	vector<lli>v;
	rep(i,1,10) v.pb(i);
	while(v.size()<k){
		t=v[n];
		if(t%10==0){
			v.pb(t*10);
			v.pb(t*10+1);
		}
		else if(t%10==9){
			v.pb(t*10+8);
			v.pb(t*10+9);
		}
		else{
			v.pb(t*10+t%10-1);
			v.pb(t*10+t%10);
			v.pb(t*10+t%10+1);
		}
		n++;
	}
	cout<<v[k-1];
	
	return 0;
}