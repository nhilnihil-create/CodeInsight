#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S,T;
  int N;
  cin>>N>>S>>T;
  
  rep(i,N){cout<<S.at(i)<<T.at(i);}
  cout<<endl;
}