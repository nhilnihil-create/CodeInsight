
// Problem : C - Maximum Volume
// Contest : AtCoder - AtCoder Beginner Contest 159
// URL : https://atcoder.jp/contests/abc159/tasks/abc159_c
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
	lli l;
	double dd;
	cin>>l;
	l=l*l*l;
	dd=l/27.0;
	cout<<fixed<<setprecision(12)<<dd;	
	return 0;
}