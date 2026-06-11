#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N=1e6+5,inf=1e18,mod=1e9+7;
#define test ll testcases;cin>>testcases; while(testcases--)
#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define sz(x) ((ll)((x).size()))
const ld pi=3.141592653589793238;

bool check_prime(ll n)
{
	ll flag=0,i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	if(n==1)
	{
		return false;
	}
	else if(flag==0 || n==2 || n==3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ll fastexpo(ll a,ll b,ll MOD) 
{
	ll result=1;
	while(b>0)
	{
		if(b%2==1)
		{
			result=(result*a)%MOD;
		}
		a=(a*a)%MOD;
		b=b/2;
	}
	return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,j,k,f;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    i=0;
    j=0;
    f=0;
    for(f=0;f<2*n;f++)
    {
    	if(f%2==0)
    	{
    		cout<<s1[i];
    		i++;
    	}
    	else
    	{
    		cout<<s2[j];
    		j++;
    	}
    }
    cout<<"\n";
	return 0;
}