#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e18+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=40000;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
int main()
{
	int i,j,k,l,m,n;
	string s;
	cin>>s;
	if(s[0]==s[1]&&s[1]==s[2]&&s[0]=='R')
		cout<<3;
	else if(s[0]==s[1]&&s[0]=='R'||s[1]=='R'&&s[1]==s[2])
		cout<<2;
	else if(s[0]=='R'||s[1]=='R'||s[2]=='R')
		cout<<1;
	else
		cout<<0;

}