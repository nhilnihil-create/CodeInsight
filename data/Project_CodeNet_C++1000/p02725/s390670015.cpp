#include <bits/stdc++.h>
using namespace std;
int main(){
  int K, N;
  cin>>K>>N;
  vector<int> house(N,0);
  vector<int> diff(N,0);
  for(int i=0; i<N; i++){
    cin>>house.at(i);
  }
  for(int i=0; i<N-1; i++){
    diff.at(i)=house.at(i+1)-house.at(i);
  }
  diff.at(N-1)=house.at(0)+K-house.at(N-1);
  sort(diff.begin(), diff.end());
  int ans=K-diff.at(N-1);
  cout<<ans<<endl;
}