#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int N;
  cin>>N;
  int W[N];
  int sum=0;
  rep(i,N){
      cin>>W[i];
      sum+=W[i];
  }
  int T=0;
  int m=1000000;
  rep(i,N){
      T+=W[i];
      sum-=W[i];
      m=min(m,abs(T-sum));
  }
  
  cout<<m<<endl;
  
}