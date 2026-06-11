#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
//1-indexed
template<typename T>
struct BIT{
	int n;
	vector<T>bit;
	BIT():n(-1){}
	BIT(int n_,T a):n(n_),bit(n_+1,a){}

	T sum(int i)
	{
		T ans=0;
		for(;i>0;i-=i&-i)ans+=bit[i];
		return ans;
	}
	void add(int i,T a)
	{
		if(i==0)return;
		for(;i<=n;i+=i&-i)bit[i]+=a;
	}
};
main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	BIT<int>a(n,0);
	int c,x,y;
	for(;~scanf("%d%d%d",&c,&x,&y);)
	{
		if(!c)a.add(x,y);
		else printf("%d\n",a.sum(y)-a.sum(x-1));
	}
}

