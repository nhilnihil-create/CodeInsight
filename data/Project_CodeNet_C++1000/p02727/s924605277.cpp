#include<bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

int x,y,a,b,c,p,q,r[100005];
multiset<int> s1,s2;

int main()
{
	scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&p);
		s1.insert(p);
		if(sz(s1)>x) s1.erase(s1.begin());
	}
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&q);
		s2.insert(q);
		if(sz(s2)>y) s2.erase(s2.begin());
	}
	for(int i=1;i<=c;i++)
		scanf("%d",&r[i]);
	sort(r+1,r+c+1,greater<int>());
	for(int i=1;i<=c;i++)
	{
		if(r[i]<=*s1.begin()&&r[i]<=*s2.begin()) break;
		if(r[i]<=*s2.begin())
		{
			s1.erase(s1.begin());
			s1.insert(r[i]);
		}
		else if(r[i]<=*s1.begin())
		{
			s2.erase(s2.begin());
			s2.insert(r[i]);
		}
		else
		{
			int num1=*s1.begin(),num2=*s2.begin();
			if(num1<=num2)
			{
				s1.erase(s1.begin());
				s1.insert(r[i]);
			}
			else
			{
				s2.erase(s2.begin());
				s2.insert(r[i]);
			}
		}
	}
	ll ans=0;
	for(multiset<int>::iterator it=s1.begin();it!=s1.end();it++)
	{
		ll num=*it;
		ans+=num;
	}
	for(multiset<int>::iterator it=s2.begin();it!=s2.end();it++)
	{
		ll num=*it;
		ans+=num;
	}
	printf("%lld\n",ans);
	return 0;
}