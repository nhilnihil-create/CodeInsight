
// Problem : B - Golden Coins
// Contest : AtCoder - AtCoder Beginner Contest 160
// URL : https://atcoder.jp/contests/abc160/tasks/abc160_b
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
	lli n,t=0,a;
	cin>>n;
	a=n%500;
	t+=(n/500)*1000;
	t+=(a/5)*5;
	cout<<t;
	return 0;
}