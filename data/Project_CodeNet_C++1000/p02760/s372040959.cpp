#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<vector<int>> A(3,vector<int>(3));
  vector<vector<int>> ans(3,vector<int>(3,0));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> A.at(i).at(j);
    }
  }
  
  int N;
  cin >> N;
  vector<int> b(N);
  for(int i=0;i<N;i++){
    cin >> b.at(i);
  }
  for(int bnum=0;bnum<N;bnum++){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(A.at(i).at(j)==b.at(bnum)){
          ans.at(i).at(j)=1;
        }
      }
    }
  }
  bool bingo = false;
  for(int i=0;i<3;i++){
    if(ans.at(i).at(0)+ans.at(i).at(1)+ans.at(i).at(2)==3){
      bingo = true;
    }
    if(ans.at(0).at(i)+ans.at(1).at(i)+ans.at(2).at(i)==3){
      bingo = true;
    }
  }
  if(ans.at(0).at(0)+ans.at(1).at(1)+ans.at(2).at(2)==3){
    bingo = true;
  }
  if(ans.at(0).at(2)+ans.at(1).at(1)+ans.at(2).at(0)==3){
    bingo = true;
  }
  if(bingo){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}