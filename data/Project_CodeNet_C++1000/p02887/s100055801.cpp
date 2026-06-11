
// Problem : C - Slimes
// Contest : AtCoder - AtCoder Beginner Contest 143
// URL : https://atcoder.jp/contests/abc143/tasks/abc143_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include<set>
#define lli long long int
#define pb push_back
#define rep(i,a,n) for(i=a;i<n;i++)
#define all(v) (v.begin(),v.end())
#define ppb pop_back
#define vsz v.size()
using namespace std;
int main()
{
	lli n,i,k=0;
	cin>>n;
	char c;
	vector<char>v;
	for(i=0;i<n;i++){
		cin>>c;
		v.pb(c);
	}
	for(i=0;i<n-1;i++){
		if(v[i]==v[i+1])
		k++;
	}
	cout<<n-k;	
	return 0;
}