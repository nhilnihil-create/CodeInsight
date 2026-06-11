#include<bits/stdc++.h>
using namespace std;
int n;
long long b[65],a[100005];
void insert(long long v){
  for(int i=59;i>=0;i--){
   if((v>>i)&1){
  if(b[i]) v^=b[i];
  else{
   b[i]=v;
   for(int j=i-1;j>=0;j--) if((b[i]>>j)&1) b[i]^=b[j];
   for(int j=i+1;j<60;j++) if((b[j]>>i)&1) b[j]^=b[i];
   break;
}
}
}
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  long long x=0;
  for(int i=0;i<n;i++){x^=a[i];}
  for(int i=0;i<n;i++){
    for(int j=0;j<60;j++){
     if(x>>j&1) a[i] &=~(1LL<<j);
}
   insert(a[i]);
}
  long long res=0;
  for(int i=0;i<60;i++) res^=b[i];
  printf("%lld\n",x+2LL*res);
}