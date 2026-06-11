#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;
const int MAX=1e6;

long long kai[MAX],kair[MAX],rev[MAX];

void com_p(){
  kai[0]=kai[1]=1;
  kair[0]=kair[1]=1;
  rev[1]=1;
  for(int i=2;i<MAX;i++){
    kai[i]=kai[i-1]*i%M;
    rev[i]=M-rev[M%i]*(M/i)%M;
    kair[i]=kair[i-1]*rev[i]%M;
  }
}
long long ncr(int n,int r){
  if(n<0||r<0) return 0;
  if(n<r) return 0;
  return kai[n]*(kair[r]*kair[n-r]%M)%M;
}

int main(){
  int x,y;
  cin>>x>>y;
  com_p();
  long long sum=0;
  for(int i=0;i<=x;i++){
    if(3*i==2*y-x){
      sum+=ncr(y-i,i);
      sum%=M;
    }
  }
  cout<<sum<<endl;
}