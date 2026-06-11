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

const int S=200100;
int n,id;
string ans[S+5];

void Rec(string s)
{
	if(sz(s)==n)
	{
		ans[id++]=s;
		return;
	}

	for(int i=0;i<=9;i++)
	{
		if(sz(s)==0)
		{
			if(i==0)continue;
			string t=s;
			t+=(i+'0');
			Rec(t);
		}
		else
		{
			int pre=s.back()-'0';
			if(abs(pre-i)>1)continue;
			string t=s;
			t+=(i+'0');
			Rec(t);
		}
	}
}

void Generate()
{
	for(int len=1;len<=10;len++)
	{
		n=len;
		string s;
		Rec(s);
	}
}

int main()
{
	id=1;
	Generate();
	int k;
	while(~sf("%d",&k))
	{
		ps(ans[k]),nl;
	}
    return 0;
}

































