#include <stdio.h>

int main(){
 int n,k,i,j,l[5005],nl,ln[2502];
 long p[5005],c[5005],m=-1000000001,d,e,g,lc[2502];
 scanf("%d",&n);
 scanf("%d",&k);
 for(i=0;i<n;i++){
  scanf("%ld",&p[i]);
  p[i]--;
 }
 for(i=0;i<n;i++){
  scanf("%ld",&c[i]);
  if(c[i]>m){
   m=c[i];
  }
  l[i]=-1;
 }
 for(i=0;i<n;i++){
  if(l[i]==-1){
   l[i]=nl;
   lc[nl]=c[i];
   ln[nl]=1;
   for(j=p[i];j!=i;j=p[j]){
    l[j]=nl;
    lc[nl]+=c[j];
    ln[nl]++;
   }
   nl++;
  }
 }
 for(i=0;i<n;i++){
  g=k%ln[l[i]];
  if(k>=ln[l[i]]){
   g+=ln[l[i]];
  }
  d=c[i];
  if(lc[l[i]]>0){
   d+=(long)((k-g)/ln[l[i]])*lc[l[i]];
  }
  e=d;
  for(g--,j=p[i];g>0;g--,j=p[j]){
   e+=c[j];
   if(e>d){
    d=e;
   }
  }
  if(d>m){
   m=d;
  }
 }
 printf("%ld",m);
 return 0;
}
