#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> P(N);
  for(int i=0; i<N; i++){
    cin>>P.at(i);
  }
  int ans=0;
  int count=1e9;
  for(int i=0; i<N; i++){
    count=min(count,P.at(i));
    if(count==P.at(i)){
      ans++;
    }
  }
  cout<<ans<<endl;
}