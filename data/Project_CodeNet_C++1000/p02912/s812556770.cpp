#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;cin>>N>>M;
  priority_queue<double> A;
  for(int i=0;i<N;i++){
    int wait;cin>>wait;
    A.push(wait);
  }
  for(int j=0;j<M;j++){
    double sale=A.top()/2;
    A.pop();
    A.push(sale);
  }
  // int ans=0;
  long ans=0;
  int Fx=0;
  while(Fx<N){
    ans += (int)A.top();
    A.pop();
    Fx++;
  }
  cout<<ans<<endl;
}