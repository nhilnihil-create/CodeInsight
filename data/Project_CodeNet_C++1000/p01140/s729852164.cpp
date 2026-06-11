#include<bits/stdc++.h>
main(){
  int n,m;
  while(scanf("%d%d",&n,&m),n){
    int i,j,h[1501],w[1501],x;
    std::map<int,int>a;
    for(x=i=0;i<n;h[++i]=x)scanf("%d",&j),x+=j;
    for(x=i=0;i<m;w[++i]=x)scanf("%d",&j),x+=j;
    for(x=i=0;i<=n;++i)for(j=0;j<=m;++j)++a[h[i]-w[j]];
    for(auto &e:a)x+=e.second*(e.second-1)/2;
    printf("%d\n",x);
  }
}