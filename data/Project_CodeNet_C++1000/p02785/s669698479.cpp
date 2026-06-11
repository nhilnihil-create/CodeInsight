#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,K;
  long long Ans=0;
  cin>>N>>K;

  vector<int> H(N);
  rep(i,N){cin >> H.at(i);}
  sort(H.begin(),H.end());
  rep(i,N-K){Ans+=H.at(i);}
  cout<<Ans<<endl;
}
