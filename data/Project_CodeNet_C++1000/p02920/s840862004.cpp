#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

multiset <int,greater<int> > s2;
multiset <int> s1;
multiset <int>::iterator it,it2;
int x,n,a[maxn];

int main()
{
	x=read(); n=(1<<x);
	for(int i=1;i<=n;i++) a[i]=read(),s1.insert(a[i]);
	it=s1.end(); it--; s1.erase(it); s2.insert(*it);
	while(s2.size()!=n)
	{
		vector <int> vec; vec.clear();
		for(multiset <int,greater<int> >::iterator it1=s2.begin();it1!=s2.end();it1++)
		{
			it2=s1.lower_bound(*it1);
			if(it2==s1.begin()) {puts("No"); return 0;}
			it2--; vec.pb(*it2); s1.erase(it2); 
		}
		for(int i=0;i<vec.size();i++) s2.insert(vec[i]);
	}
	puts("Yes");
	return 0;
}