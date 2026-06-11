#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,id[maxn],x_[maxn],y_[maxn],tot;
inline void add(int x,int y) { x_[++tot]=x,y_[tot]=y; }
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=16;i++)
		if((1<<i)==n) return puts("No"),0;
	add(1,2),add(2,3),add(3,n+1),add(n+1,n+2),add(n+2,n+3);
	for(int i=4;i<n;i+=2)
		add(i,i+1),add(i+1,n+1),add(n+1,n+i),add(n+i,n+i+1);
	if(!(n&1))
	{
		#define id(x) ((x&1)?x:x+n)
		for(int i=2;i<n;i++)
			if((n^i^1)<n) { add(n,id(i)),add(id(n^i^1),2*n); break; }
	}
	puts("Yes");
	for(int i=1;i<=tot;i++) printf("%d %d\n",x_[i],y_[i]);
	return 0;
}