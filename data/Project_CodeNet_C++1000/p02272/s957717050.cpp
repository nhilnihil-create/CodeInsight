#include<cstdio>
int i,j,k,o,n,c,s[500000];
void g(int l,int m,int r){
  int L[m-l+1],R[r-m+1];
  for(i=0;i<m-l;++i)L[i]=s[i+l];
  for(i=0;i<r-m;++i)R[i]=s[i+m];
  L[m-l]=R[r-m]=1e9,i=o=0;
  for(k=l;k<r;++c)s[k++]=L[i]>R[o]?R[o++]:L[i++];
}
void e(int l,int r){
  int m=(l+r)/2;
  if(l+1<r)e(l,m),e(m,r),g(l,m,r);
}
main(){
  for(scanf("%d",&n);i<n;scanf("%d",&s[i++]));
  e(0,n);
  for(;j<n;)printf(j-n?"%d ":"%d\n",s[j++]);
  printf("%d\n",c);
}