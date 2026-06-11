#include<bits/stdc++.h>
const unsigned long long int M= 1000000007;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()	
#define fr(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define int long long 
#define endl "\n"
using namespace std;
int power(int x,int y){int res=1;while(y>0){if(y&1)res=x*res; y=y>>1;x=x*x;}return res;}
int power(int x,int y,int mod){int res=1;while(y>0){if(y&1)res=x*res%mod; y=y>>1;x=x*x%mod;}return res;}

void nik()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}

 	#define F first 
	#define S second 


signed main()
{	nik();


int test=1;
//cin>>test;
while(test--)
{
int n;
cin>>n;

int a[n];
fr(i,n)cin>>a[i];

int money=1000,prev=a[0];
bool st=1;

int ans=money;
int pm=money;
int stock=money/a[0];
money-=a[0]*stock;
int ps=stock;

for(int i=1;i<n;i++)
{
	if(st)
	{
		if(a[i]<prev)
			{
				
				stock=pm/a[i];
				money=pm-a[i]*stock;
			}
		else if(a[i]>prev)
			{
				pm=money;
				money+=a[i]*stock;
				ans=max(ans,money);
				ps=stock;
				stock=0;
				st=0;
			}
	}
	else
	{
		if(a[i]>prev)
		{
			money=pm+a[i]*ps;
			ans=max(ans,money);
		}
		else if(a[i]<prev)
		{
			ps=stock;
			stock=money/a[i];
			pm=money;
			money-=a[i]*stock;
			st=1;
			
		}
	}


	prev=a[i];
}

cout<<ans<<endl;






	}
return 0;
}


