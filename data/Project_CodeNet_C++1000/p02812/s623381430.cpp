#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {

  int N,Ans=0;
  string S;
  cin>>N>>S;
  
  rep(i,N-2){if(S.at(i)=='A'){if(S.at(i+1)=='B'){if(S.at(i+2)=='C'){Ans++;}}}}
  cout<<Ans<<endl;
}