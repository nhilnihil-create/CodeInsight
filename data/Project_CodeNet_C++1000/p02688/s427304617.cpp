#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,K;
  cin>>N>>K;
  vector<int> vec(N);
  
  rep(i,N){vec.at(i)=1;}
  
  int d,A;
  
  rep(i,K){cin>>d;
           rep(j,d){cin>>A;
                   vec.at(A-1)=0;}
          }
  int Ans=0;
  rep(i,N){Ans+=vec.at(i);}
  
  cout<<Ans<<endl;
}