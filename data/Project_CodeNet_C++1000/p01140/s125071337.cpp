#include<bits/stdc++.h>
int n,m,i,j,h[1501],w[1501],p[1<<21],q[1<<21],x,b;
main(){
  while(scanf("%d%d",&n,&m),n){
    for(x=i=0;i<n;)scanf("%d",h+i++);
    for(x=i=0;i<m;)scanf("%d",w+i++);
    for(i=0;i<n;++i)for(b=0,j=i;j<n;++p[b])b+=h[j++];
    for(i=0;i<m;++i)for(b=0,j=i;j<m;++q[b])b+=w[j++];
    for(i=0;i<1<<21;p[i]=q[i++]=0)x+=p[i]*q[i];
    printf("%d\n",x);
  }
}