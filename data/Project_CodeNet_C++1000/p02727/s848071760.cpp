#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree < pairs ,  null_type , greater<pairs>,  rb_tree_tag ,  tree_order_statistics_node_update > 
#define ll long long
#define lld long double
#define vc vector<ll>
const ll MOD=(1e9 +7);
typedef pair<ll,ll>pairs;
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;b--;}a=(a*a)%MOD;b>>=1;}
    return res;}

int main() {
	// your code goes here
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll t,x,y,a,b,n,i,j,k,l,c,f;
	cin>>x>>y>>a>>b>>c;
	vc p(a+1),q(b+1),r(c+1);
	for(i=1;i<=a;i++)cin>>p[i];
	for(i=1;i<=b;i++)cin>>q[i];
	for(i=1;i<=c;i++)cin>>r[i];
	sort(p.begin()+1,p.end(),greater<ll>());
	sort(q.begin()+1,q.end(),greater<ll>());
	sort(r.begin()+1,r.end(),greater<ll>());
	ll ind1=x,ind2=y;
	for(i=1;i<=c;i++)
	{
	    if((ind1>0&&ind2>0)&&(r[i]>p[ind1])&&(r[i]>q[ind2]))
	    {
	        if(p[ind1]>q[ind2])
	            ind2--;
	        else ind1--;
	    }
	    else if((ind1>0)&&r[i]>p[ind1])
	        ind1--;
	    else if((ind2>0)&&r[i]>q[ind2])
	        ind2--;
	   else break;
	}
	ll sum=0;
	for(j=1;j<=ind1;j++)sum+=p[j];
	for(j=1;j<=ind2;j++)sum+=q[j];
	for(j=1;j<i;j++)sum+=r[j];
	cout<<sum;
	return 0;
}
