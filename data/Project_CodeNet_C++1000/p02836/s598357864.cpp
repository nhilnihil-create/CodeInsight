#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin>>S;
  int N=S.length(),Ans=0;
  rep(i,N/2){if(S.at(i)!=S.at(N-i-1))Ans++;}
  cout<<Ans<<endl;
}