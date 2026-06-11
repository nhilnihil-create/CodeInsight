#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<ctime>
#include<bitset>
//#include<unordered_map>
using namespace std;
#define ull unsigned long long int
#define ll long long
#define dd cout<<endl
const long long int inf = 1e18+7;
const int mod = 998244353;

inline ll max(ll a,ll b) { return a>b?a:b; }
inline ll min(ll a,ll b) { return a<b?a:b; }
inline ll abs1(ll a) { return a>0?a:-a; }

const int maxn=1e5+10;

const int seed=2333;
ull base[maxn];
ull h[maxn];

int n,len;
string str;

inline ull get_hash(int left,int right)//区间hash 
{
	return h[right]-h[left-1]*base[right-left+1];
}

inline bool judge(int x)
{
	for(int i=1;i+x-1<=len;i++)
	{
		ull res=get_hash(i,i+x-1);
		
		for(int j=i+x;j+x-1<=len;j++)
		{
			ull res1=get_hash(j,j+x-1);
			
			if(res == res1)
				return true;
		}
	}
	return false;
}

int main()
{
	while(cin>>n)
	{
		cin>>str;
		len=str.size();
		str.insert(0,"#");//下标从1开始
		
		h[0]=0,base[0]=1;
		for(int i=1;i<=len+1;i++)
		{
			h[i]=h[i-1]*seed+str[i];
			base[i]=base[i-1]*seed;
		} 
		
		int left=1,right=len+1,mid;
		while(left<=right)
		{
			mid=(left+right)>>1;
			if(judge(mid))
				left=mid+1;
			else
				right=mid-1;
		}
		cout<<right<<endl;
	}
	return 0;
}