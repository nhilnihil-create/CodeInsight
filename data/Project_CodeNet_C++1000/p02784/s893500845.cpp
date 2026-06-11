#include <bits/stdc++.h>
using namespace std;
int main(){
int H,N;
  cin>>H>>N;
  vector<int>attack(N);
  for(int i=0;i<N;i++){
  cin>>attack.at(i);
  }
  int hp;
    for(int i=0;i<N;i++){
  H-=attack.at(i);
  }
  if(H<=0){
  cout<<"Yes";
  }
  else{
  cout<<"No";
  }
}
