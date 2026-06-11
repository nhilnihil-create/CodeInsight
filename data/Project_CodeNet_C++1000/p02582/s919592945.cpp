
// Problem : A - Rainy Season
// Contest : AtCoder - AtCoder Beginner Contest 175
// URL : https://atcoder.jp/contests/abc175/tasks/abc175_a
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
string  s;cin>>s;
int cnt=0,ans=0;
char cmp='R';
fr(i,0,s.size())
{
	if(s[i]==cmp) cnt++;
	else 
	{
		ans=max(ans,cnt);
		cnt=0;
	}
}
cout<<max(ans,cnt);
return 0;
}