#include<bits/stdc++.h>
#define rep(i,N) for(int i=1;i<=N;i++)
using namespace std;
int gcd(int p,int q){
  if(p%q==0)return q;
  return gcd(q,p%q);
}


int main(void){
   int N;
   cin>>N;
   long long a=0;
   rep(i,N)rep(j,N)rep(k,N)a+=gcd(i,gcd(j,k));
   cout<<a<<endl;
   return 0;
   
}


