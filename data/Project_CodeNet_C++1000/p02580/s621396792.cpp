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
typedef pair<int,int>pii;

const int S=100100;
int main()
{
	int row,col,m;
	while(~sf("%d %d %d",&row,&col,&m))
	{
		int rf[row+5],cf[col+5];
		mem(rf,0);
		mem(cf,0);
		map<pii,bool>mp;
		for(int i=0;i<m;i++)
		{
			int r,c;
			sf("%d %d",&r,&c);
			rf[r]++;
			cf[c]++;
			mp[pii(r,c)]=true;
		}

		int mxr=*max_element(rf+1,rf+1+row);
		vector<int>mxvr;
		for(int i=1;i<=row;i++)
		{
			if(rf[i]==mxr)
			{	
				mxvr.push_back(i);
			}
		}

		int mxc=*max_element(cf+1,cf+1+col);
		vector<int>mxvc;
		for(int i=1;i<=col;i++)
		{
			if(cf[i]==mxc)
			{	
				mxvc.push_back(i);
			}
		}

		bool f=false;
		for(int r:mxvr)
		{
			for(int c:mxvc)
			{
				if(!mp[pii(r,c)])
				{
					f=true;
					break;
				}
			}
			if(f)break;
		}
		int ans=mxr+mxc;
		if(!f)ans--;
		pf("%d\n",ans);
	}	
    return 0;
}

































