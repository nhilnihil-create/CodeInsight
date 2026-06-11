#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,A,X=1,Ans=0;
  cin>>N;
  rep(i,N){cin>>A;
          if(A==X){X++;}else{Ans++;}
          }
  if(Ans==N){cout<<-1<<endl;}else{cout<<Ans<<endl;}
}