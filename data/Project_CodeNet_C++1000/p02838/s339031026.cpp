#include <bits/stdc++.h>
#define ll long long int 
#define endl '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 100000000 
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll a[n],ans=0,x=1;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    for(int i=0;i<63;i++)
    {
    	ll a1=0,b=0;
    	//cout<<x<<" ";
    	for(int j=0;j<n;j++)
    	{
    		if(a[j]&x)
    		{
    			a1++;
    		}
    		else
    		b++;
    	}
    	a1=a1*b;
    	a1=a1%MOD;
    	a1=((a1%MOD)*(x%MOD))%MOD;
    	//cout<<a1<<" ";
    	x=x*2;
    	ans=(ans+a1)%MOD;
    }
    cout<<ans<<endl;
}