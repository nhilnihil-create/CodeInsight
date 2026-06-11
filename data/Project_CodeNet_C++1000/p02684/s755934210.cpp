#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  long long K;
  cin >> N >> K;
  vector<vector<int>> next(60,vector<int>(N));
  for(int j=0;j<N;j++){
    cin >> next.at(0).at(j);
    next.at(0).at(j)--;
  }
  for(int i=0;i<59;i++){
    for(int j=0;j<N;j++){
      next.at(i+1).at(j)=next.at(i).at(next.at(i).at(j));
    }
  }
  int j=0;
  for(int i=0;i<60;i++){
    if(K & (1LL<<i)){
      j=next.at(i).at(j);
    }
  }
  cout << j+1 << endl;
} 