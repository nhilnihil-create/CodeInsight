
// Problem : B - String Palindrome
// Contest : AtCoder - AtCoder Beginner Contest 159
// URL : https://atcoder.jp/contests/abc159/tasks/abc159_b
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
bool check(string s){
	string p="";
	for(lli i=s.length()-1;i>=0;i--)
	p+=s[i];
	if(p==s) return true;
	else return false;
	
}
int main()
{
	lli n;
	string s,t,k;
	cin>>s;
	n=s.length();
	t=s.substr(0,(n-1)/2);
	k=s.substr((n+3)/2-1,n-1/2);
	// cout<<t<<" "<<k<<"\n";
	if(check(s)&&check(t)&&check(k)){
		cout<<"Yes";
	}
	else
	cout<<"No";
	return 0;
}