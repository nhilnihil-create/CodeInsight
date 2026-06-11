#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin>>N>>K;
  
  vector<bool> have(N, false);

  for(int i=0;i<K;i++){
    int sunuke=0;
    cin>>sunuke;
    for(int s=0;s<sunuke;s++){
      int tmp;
      cin>>tmp;
      have.at(tmp-1)=true;
    }
  }
  int ans=0;
  for(auto h: have){
    if(!h){
      ans++;
    }
  }
  cout<<ans<<endl;
}