#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long long N,A,B,Ans=0;
  cin>>N>>A>>B;
  Ans=N/(A+B)*A;
  if(N%(A+B)<A){Ans=Ans+N%(A+B);}else{Ans=Ans+A;}
  cout<<Ans<<endl;
}