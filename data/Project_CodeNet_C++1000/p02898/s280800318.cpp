#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,K,x,Ans=0;
  cin>>N>>K;
  
  rep(i,N){cin>>x;
           if(x>=K){Ans++;}
          }
  cout<<Ans<<endl;
}