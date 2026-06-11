#include<cstdio>

int n,m;
inline int lowbit(int x) {
	return x&(x-1);
}
inline void Pt(int u,int v) {
	printf("%d %d\n",u,v);
}
int main() {
	scanf("%d",&n);
	if(lowbit(n)==0) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=1;i<=2;i++)
		Pt(i,i+1),Pt(n+i,n+i+1);
	Pt(3,n+1);
	if(n%2==0)
		m=n--;
	else m=n;
	for(int i=4;i<=n;i++)
		Pt(1,i),Pt(i,m+(i^1));
	if(m>n) {
		int p=lowbit(m);
		Pt(m,p+1),Pt(m-p,2*m);
	}
	return 0;
}