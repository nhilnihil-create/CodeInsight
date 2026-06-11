#include <bits/stdc++.h>
using namespace std;

void bingo(int a1, int a2, int a3, vector<bool>& judge);

int main(){
  vector<int> A(9);
  for (int i = 0; i < 9; i++){
    cin >> A.at(i);
  }
  
  int N;
  cin >> N;
  
  vector<bool> judge(9, false);
  for (int i = 0; i < N; i++){
    int B;
    cin >> B;
    
    for (int j = 0; j < 9; j++){
      if (A.at(j) == B){
        judge.at(j) = true;
        break;
      }
    }
    
  }
  
  bingo(0,1,2,judge);
  bingo(3,4,5,judge);
  bingo(6,7,8,judge);
  bingo(0,3,6,judge);
  bingo(1,4,7,judge);
  bingo(2,5,8,judge);
  bingo(0,4,8,judge);
  bingo(2,4,6,judge);
  
  cout << "No" << endl;
}

void bingo(int a1, int a2, int a3, vector<bool>& judge){
  if (judge.at(a1) == true && judge.at(a2) == true && judge.at(a3) == true){
    cout << "Yes" << endl;
    exit(0);
  }
}