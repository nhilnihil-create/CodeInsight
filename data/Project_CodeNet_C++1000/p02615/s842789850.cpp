#include<bits/stdc++.h>
#define N 1000005
#define LL long long
using namespace std;

int n;
LL a[N],ans;
priority_queue<int>q;

inline int qr()
{
	int x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

inline LL qrl()
{
	LL x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

int main()
{
	n=qr();
	for(register int i=1;i<=n;i++)
		a[i]=qrl();
	sort(a+1,a+n+1);
	q.push(a[n]);
	for(register int i=n-1;i>=1;i--)
	{
		//cout<<q.top()<<endl;
		ans+=q.top();
		q.pop();
		q.push(a[i]);
		q.push(a[i]);
	}
	cout<<ans<<endl;
	return 0;
} 