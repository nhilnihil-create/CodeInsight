# include <cstdio>
# include <cstring>
# define N 400010
int n,a[N],b[N],tree[N];
void add(int x,int y) {
	int i;
	for(i=x;i<=n;i+=i&(-i)) tree[i]+=y;
}
int query(int x) {
	int i,ans=0;
	for(i=x;i>=1;i-=i&(-i)) ans+=tree[i];
	return ans;
}
void prt() {
	for(int i=1;i<=n;i++) printf("%d ",n);
}
int main() {
	int k,i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	if(k>40) {prt(); return 0;}
	while(k--) {
		memset(tree,0,sizeof(tree));
		for(i=1;i<=n;i++) {
			b[i]=query(n)-query(i-1);
			add(a[i]+i>n?n:a[i]+i,1);
		}
		memset(tree,0,sizeof(tree));
		for(i=n;i>=1;i--) {
			b[i]+=query(i)+1;
			add(i-a[i]<1?1:i-a[i],1);
		}
		memcpy(a,b,sizeof(b));
	}
	for(i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}