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

const int S=100100;
int main()
{
	int n,x,y;
	while(~sf("%d %d %d",&n,&x,&y))
	{
		int ara[n+5];
		mem(ara,0);
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int dis1=j-i;
				int dis2=abs(i-x)+abs(y-j)+1;
				int dis=min(dis1,dis2);
				ara[dis]++;
			}
		}

		for(int i=1;i<=n-1;i++)pf("%d\n",ara[i]);
	}
    return 0;
}

































