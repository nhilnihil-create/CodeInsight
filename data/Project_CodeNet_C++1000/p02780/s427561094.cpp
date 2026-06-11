#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,Z=0,A;
  cin>>N>>K;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
    p[i]++;
    if(i<K){
      A+=p[i];
    }
  }
  Z=A;
  for(int i=K;i<N;i++){
    Z-=p[i-K];
    Z+=p[i];
    A=max(A,Z);
  }
  double E=A,P=2;
  cout<<fixed<<setprecision(15);
  cout<<E/P<<endl;
}