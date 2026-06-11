#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long mypow(long x,long p){
  if(p==0)return 1;
  if(p%2)return mypow(x,p-1)*x%MOD;
  long y=mypow(x,p/2);return y*y%MOD;
}
long inv(long x){
  return mypow(x,MOD-2);
}
long COM(long n,long k){
  long x=1;
  for(long i=1;i<=n;i++)x=x*i%MOD;
  for(long i=1;i<=k;i++)x=x*inv(i)%MOD;
  for(long i=1;i<=n-k;i++)x=x*inv(i)%MOD;
  return x;
}
int main(){
  long x,y;cin>>x>>y;
  if((x+y)%3!=0||x<(x+y)/3||x>2*(x+y)/3){
    cout<<0;return 0;
  }
  cout<<COM((x+y)/3,x-(x+y)/3)<<endl;
}

