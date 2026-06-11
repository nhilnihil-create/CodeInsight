#include<bits/stdc++.h>
using namespace std;

int main(){
  int l, r, d;
  cin>>l>>r>>d;
  
  vector<int> in;
  
  for(int i=l;i<=r;++i){
    in.push_back(i);
  }
  int cnt = 0;
  for(int x: in){
    if(x%d == 0){
      cnt++;
    }
  }
  cout<<cnt<<endl;
  
  return 0;
}