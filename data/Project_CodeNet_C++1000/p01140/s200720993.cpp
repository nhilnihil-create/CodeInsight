#include<bits/stdc++.h>
int n,m,i,j,h[1500],w[1500],p[1<<21],q[1<<21],x,a,b;
void c(int n,int*p,int*h){
  for(i=0;i<n;++i)for(x=0,j=i;j<n;++p[x])x+=h[j++];
}
main(){
  while(scanf("%d%d",&n,&m),n){
    for(a=i=0;i<n;a+=h[i++])scanf("%d",h+i);c(n,p,h);
    for(b=i=0;i<m;b+=w[i++])scanf("%d",w+i);c(m,q,w);
    for(x=i=0;i<=(a<b?b:a);p[i]=q[i++]=0)x+=p[i]*q[i];
    printf("%d\n",x);
  }
}