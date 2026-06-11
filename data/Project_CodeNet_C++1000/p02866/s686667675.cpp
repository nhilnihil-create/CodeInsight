#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf pop_front()
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define mod 1000000007
#define mod2 1000000006
#define inf 100000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<lli>
#define vii vector<int>
#define is indexed_set
#define eps 0.000001
#define endl '\n'
#define mo 998244353
#define pi 3.141592653589793
 
using namespace std ;
 
typedef tree<pair<pll,lli>,null_type,less<pair<pll,lli>>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
 
#define MAXN 200000

lli power(lli x, lli y, lli p) 
{ 
    lli res = 1;   
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;  
        x = (x*x) % p;   
    } 
    return res; 
}
 
int main()
{
    
/////////////////////////////////////
    
    fastio;
 
/////////////////////////////////////  
  
	lli n;
	cin>>n;
	lli a[n+1],cnt[n]={0};

	loopl(i,1,n+1)
	{
		cin>>a[i];
		cnt[a[i]]++;

	}

	if(a[1] !=0 || cnt[0]>1)
	{
		cout<<0;
		return 0;
	}

	lli ans=1;
	loopl(i,1,n)
	{
		ans = ans*power(cnt[i-1],cnt[i],mo);
		ans %= mo;
	}

	cout<<ans;
}

        
 
