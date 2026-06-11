#include <iostream>

int ans,n,m,p[100005];
int rt(int i) { return (p[i]==i?i:p[i]=rt(p[i])); }

int main() {
  scanf("%d %d",&n,&m);
  ans=n-1;
  for (int i=0;i<n;i++) p[i]=i;
  for (int i=0;i<m;i++) {
	int u,v;
    scanf("%d %d",&u,&v);
	int a=rt(u),b=rt(v);
    if (a!=b) p[a]=b,ans--;
  }
  printf("%d",ans);
}