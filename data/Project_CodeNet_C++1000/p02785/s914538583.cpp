#include<bits/stdc++.h>
using namespace std;
int main() {
  long long N,K,F=0;cin>>N>>K;
  if(N<=K){
    cout<<0<<endl;return 0;
  }
  vector<long long>V(N);
  for(int X=0;X<N;X++)cin>>V[X];
  sort(V.begin(),V.end());
  for(int X=0;X<N-K;X++)F+=V[X];
  cout<<F<<endl;
}