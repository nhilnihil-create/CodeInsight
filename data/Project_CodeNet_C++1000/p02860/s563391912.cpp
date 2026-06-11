 
// Problem : B - Echo
// Contest : AtCoder - AtCoder Beginner Contest 145
// URL : https://atcoder.jp/contests/abc145/tasks/abc145_b
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
int main()
{
	lli n;
	string s,a,b;
	cin>>n>>s;
	if(n&1)
	cout<<"No";
	else{
		b=s.substr(0,n/2);
		a=s.substr(n/2,n-1);
		if(a==b)
		cout<<"Yes\n";
		else
		cout<<"No";
	}
	
	
	return 0;
}