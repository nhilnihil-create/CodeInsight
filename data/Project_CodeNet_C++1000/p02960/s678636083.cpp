/* Author - thiolhub */

#include <bits/stdc++.h>

using namespace std;

#define ll              long long int
#define ld              long double
#define db              double
#define pi              3.1415926535897932384626
#define PI              acos(-1.0)
#define endl            "\n"
#define mod             1000000007
#define mk              make_pair
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(t)            ll t; cin>>t; while(t--)
#define sc(a)	        scanf("%lld",&a);
#define pr(a)	        printf("%lld\n",a)
#define f(i,a,n)		for(ll i=a;i<n;i++)
#define m(a)		    memset(a,0,sizeof(a))
#define FastIO          ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)



int main(){ FastIO;

int i,j,d,n;string s;
cin>>s;n=s.length();
vector<int> dp(13,0);
if(s[0]!='?') dp[s[0]-'0']+=1;
else
{
	for(i=0;i<10;i++) dp[i]+=1;
}
for(i=1;i<n;i++)
{
	vector<int> tdp(13,0);
	if(s[i]!='?') {
	d=s[i]-'0';
	for(j=0;j<13;j++)
	{
		int r=(10*j+d)%13;
		tdp[r]=(tdp[r]+dp[j])%mod;
	}
	}
	else
	{
		for(d=0;d<10;d++)
		{
			for(j=0;j<13;j++)
			{
				int r=(10*j+d)%13;
				tdp[r]=(tdp[r]+dp[j])%mod;
			}
		}
	}
	dp=tdp;
}
cout<<dp[5];


return 0;
}