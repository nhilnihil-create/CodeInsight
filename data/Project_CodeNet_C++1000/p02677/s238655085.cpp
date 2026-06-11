
// Problem : C - : (Colon)
// Contest : AtCoder - AtCoder Beginner Contest 168
// URL : https://atcoder.jp/contests/abc168/tasks/abc168_c
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
	lli h,k,a,b,i;
	cin>>a>>b>>h>>k;
	double t,n;
	n=h*30 + k/2.0;
	t=6*k;
	t=n-t;
	t=(pi*t)/180;
	n=a*a+b*b-2*a*b*cos(t);
	cout<<fixed<<setprecision(20)<<sqrt(n);
	return 0;
}