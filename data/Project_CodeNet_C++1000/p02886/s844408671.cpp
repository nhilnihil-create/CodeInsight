#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,Ans=0;
  cin>>N;
  vector<int> vec(N);
  
  rep(i,N){cin >> vec.at(i);}
  
  rep(i,N-1){
   for (int j = i+1; j < N; j++){
     Ans+=vec.at(i)*vec.at(j);
   }
  }
  cout<<Ans<<endl;
}