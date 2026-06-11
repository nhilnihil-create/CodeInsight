#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,Ans=1;
  string S;
  cin>>N>>S;
  rep(i,N-1){if(S.at(i)!=S.at(i+1)){Ans++;}}
  cout<<Ans<<endl;
}