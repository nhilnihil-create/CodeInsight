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
 
using namespace std ;
 
typedef tree<lli,null_type,less<lli>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
 
#define N 100000+5

lli maxSubarrayXOR(lli set[],lli n) 
{ 
    lli index = 0; 
   
    for (lli i = 60; i >= 0; i--) 
    {  
        lli maxInd = index; 
        lli maxEle = -1*inf; 
        for (lli j = index; j < n; j++) 
        {  
            if ( (set[j] & (1ll << i)) != 0  
                     && set[j] > maxEle ) 
                maxEle = set[j], maxInd = j; 
        } 
  
        if (maxEle == -1*inf) 
        continue; 
  
        swap(set[index], set[maxInd]); 
  		maxInd = index; 
  		for (lli j=0; j<n; j++) 
        { 
            if (j != maxInd && 
               (set[j] & (1ll << i)) != 0) 
                set[j] = set[j] ^ set[maxInd]; 
        } 
  
        index++; 
    } 
  
    lli res = 0; 
    for (lli i = 0; i < n; i++) 
        res ^= set[i]; 
    return res; 
} 

int main () 
{
/////////////////////////////////////
    
    fastio;
 
/////////////////////////////////////    
 
	lli n;
	cin>>n;

	lli a[n],b[n];
	loopl(i,0,n) 
	{
		cin>>a[i];
		b[i]=a[i];
	}

	lli ans=0,cnt[61]={0};

	loopl(i,0,n)
	{
		loopl(j,0,61)
		{
			if(a[i]&(1ll<<j)) cnt[j]++;
		}
	}

	loopl(j,0,61)
	{
		if(cnt[j]%2 == 1)
		{
			// cout<<j<<" "<<(1ll<<j)<<endl;
			ans += (1ll<<j);
			loopl(i,0,n)
			{
				if(b[i]&(1ll<<j))
					b[i] = (b[i]&(~(1ll<<j)));
			}
		}
	}
	ans += 2*maxSubarrayXOR(b,n);
	cout<<ans;
}	