#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
	#define debug(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define debug(...) 42
#endif

#define sf scanf
#define pf printf
#define nl printf("\n")
#define ps(s) printf("%s",s.c_str())
#define mem(x,val) memset(x,val,sizeof x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend() 
#define sz(x) (int)(x).size()
#define test_case int ___t;scanf("%d", &___t);for(int cs=1;cs<=___t;cs++)

inline string getString(int n){char ch[n+5];sf(" %s",ch);return string(ch);}
inline string getLine(int n)
{char ch[n+5];fgets(ch,n+5,stdin);string s=string(ch);s.pop_back();return s;}

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;
typedef long long ll;

const ll inf=1e18;
const int S=100100;
int main()
{
	int n,k;
	while(~sf("%d %d",&n,&k))
	{
		int P[n+5];
		for(int i=1;i<=n;i++)sf("%d",&P[i]);

		int C[n+5];
		for(int i=1;i<=n;i++)sf("%d",&C[i]);

		ll ans=-inf;
		for(int i=1;i<=n;i++)
		{
			ll siz,sum,mx;
			auto Cal = [&](int to) 
			{
				int cycleSize=0;
				ll cycleSum=0;
				ll curmx=-inf;
				int x=i;
				while(true)
				{
					cycleSum+=C[x];
					curmx=max(curmx,cycleSum);
					cycleSize++;
					x=P[x];
					if(cycleSize==to || x==i)break;
				}
				siz=cycleSize;
				sum=cycleSum;
				mx=curmx;
			};

			ll cur=-inf;
			Cal(k);
			if(siz>=k || sum<=0)
			{
				cur=mx;
			}
			else
			{
				ll full=k/siz;
				ll half=k%siz;
				
				ll sum1=(sum*(full-1))+mx;
				ll sum2=(sum*full);
				if(half>0)
				{
					Cal(half);
					if(mx>0)sum2+=mx;
				}
				cur=max(sum1,sum2);
			}
			ans=max(ans,cur);
		}
		pf("%lld\n",ans);
	}
    return 0;
}

































