#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin>>N>>K;
  vector<bool> have(N, false);

  for(int i=0;i<K;i++){
    int su=0;
    cin>>su;
    for(int s=0;s<su;s++){
      int tmp;
      cin>>tmp;
      have.at(tmp-1)=true;
    }
  }
  cout<<count(have.begin(), have.end(), false)<<endl;
}