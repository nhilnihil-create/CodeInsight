#include <bits/stdc++.h>
using namespace std;

map<int, pair<int, int>> A;
vector<vector<bool>> board(3, vector<bool>(3, false));

int main(){
  int N, K;
  cin>>N>>K;

  int count=0;
  while(N>0){
    N /= K;
    count++;
  }
  cout<<count<<endl;
}