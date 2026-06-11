#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
int main() {
  ll A,B,K;
  cin>>A>>B>>K;
  if(K>=A){
    B=A+B-K;
    A=0;
  }
  else{
    A=A-K;
  }
  ll D=0;
  B=max(D,B);
  cout<<A<<' '<<B<<endl;
}
