
// Problem : B - Multiple of 9
// Contest : AtCoder - AtCoder Beginner Contest 176
// URL : https://atcoder.jp/contests/abc176/tasks/abc176_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i>=b;i--)
//vector
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define pp pop_back
//pair
#define pi pair<int ,int >
#define mk make_pair
#define ff first
#define ss second
//set
#define si set<int>
#define sit set<int>::iterator 
using namespace std;
int main()
{
	/*
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	#endif
	*/
fast;
string s;cin>>s;
ll ans=0;
fr(i,0,s.size())
{
	ans+=(s[i]-'0');
}
if(ans%9) cout<<"No";
else cout<<"Yes";
return 0;
}