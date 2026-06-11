#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pi acos(-1.0)
#define eps 1e-9
#define ll long long
#define ull unsigned long long
#define sf scanf
#define pf printf
#define nl printf("\n")
#define ps(s) printf("%s",s.c_str())
#define	inf (ll)1e15
#define mod 1000000007
#define mem(x,val) memset(x,val,sizeof x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend() 
#define sz(x) (int)(x).size()
#define test_case int ___t;scanf("%d", &___t);for(int cs=1;cs<=___t;cs++)

using namespace __gnu_pbds;
using namespace std;

inline string getString(int n){char ch[n+5];sf(" %s",ch);return string(ch);}
inline string getLine(int n)
{char ch[n+5];fgets(ch,n+5,stdin);string s=string(ch);s.pop_back();return s;}

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;


const int S=100100;

ll bigMod(ll b, ll p, ll m)
{
    ll ret=1,cur=b%m;
    while(p)
    {
    	if(p&1)ret=(ret*cur)%mod;
    	cur=(cur*cur)%mod;
    	p>>=1;
    }
    return ret;
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif
	ll n,k;
	while(~sf("%lld %lld",&n,&k))
	{
		ll ans=0;
		ll cnt[k+5];
		for(ll i=k;i>=1;i--)
		{
			ll tot=bigMod(k/i,n,mod);
			ll sub=0;
			for(int mul=2*i;mul<=k;mul+=i)
			{
				sub=(sub+cnt[mul])%mod;
			}
			tot=(tot-sub+mod)%mod;
			cnt[i]=tot;

			tot=(tot*i)%mod;
			ans=(ans+tot)%mod;
		}
		pf("%lld\n",ans);
	}
    return 0;
}

































