#include <bits/stdc++.h>
using namespace std;

int main() {
  //ビンゴカードを作る
  vector<vector<int>> vec(3,vector<int> (3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> vec.at(i).at(j);
    }
  }
  int n;
  cin >> n;
  //それぞれのbについて、カードの数字と一致したらカードを0にする
  for(int k=0;k<n;k++){
    int b;
    cin >> b;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(b == vec.at(i).at(j))
          vec.at(i).at(j) = 0;
      }
    }
  }
  bool a = 0,ans = 0;
  
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      //0じゃないときaを1にする
      if(vec.at(i).at(j) != 0){
        a = 1;
      }
    }
    //全部0なら答えを1にする
    if(a == 0)
     ans = 1;
    a = 0;
  }
  for(int j=0;j<3;j++){
    for(int i=0;i<3;i++){
      if(vec.at(i).at(j) != 0){
        a = 1;
      }
    }
    if(a == 0)
      ans = 1;
    a = 0;
  }
  if(vec.at(0).at(0) == 0 && vec.at(1).at(1) == 0 && vec.at(2).at(2) == 0)
    ans = 1;
  if(vec.at(0).at(2) == 0 && vec.at(1).at(1) == 0 && vec.at(2).at(0) == 0)
    ans = 1;
  if(ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}