#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,minx=1000000,Ans=0;
  cin>>N;
  vector<int> P(N);
  rep(i,N){cin>>P.at(i);
          if(P.at(i)<=minx){minx=P.at(i);Ans++;}
          }
  cout<<Ans<<endl;
}
