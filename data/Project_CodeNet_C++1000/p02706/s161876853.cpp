#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,M,A,Ans=0;
  cin>>N>>M;
  rep(i,M){cin >> A;
          Ans+=A;}
  Ans=N-Ans;
  if(Ans<0){cout<<-1<<endl;}else{cout<<Ans<<endl;}
}