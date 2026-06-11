#include <bits/stdc++.h>
using namespace std;

int main () {
  int N,M,X;
  cin >> N >> M >> X;
  vector<int>C(N);
  vector<vector<int>> data(N, vector<int>(M));
  vector<int>skills(M,0);
 
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
    for (int j = 0; j < M; j++) {
      cin >> data.at(i).at(j);
      skills.at(j) += data.at(i).at(j);
    }
  }
  
  for (int i = 0; i < M; i++) {
    if (skills.at(i) < X){
      cout << -1 << endl;
      return 0;
    }
  }
  
  int Min = 10000000;

  // すべての選び方を試して、総和がKになるものがあるかを調べる
  for (int tmp = 0; tmp < (1 << 12); tmp++) {
    bitset<12> s(tmp);  // 最大20個なので20ビットのビット列として扱う
    
    if (N < 12 && s.test(N)) {
      break;
    }

    // ビット列の1のビットに対応する整数を選んだとみなして総和を求める
    int price = 0;
    vector<int>skill(M,0);
    
    for (int i = 0; i < N; i++) {
      if (s.test(i)) {
        for (int j = 0; j < M; j++) {
          skill.at(j) += data.at(i).at(j);
        }
        price += C.at(i);
      }    
    }
    for (int i = 0; i < M; i++) {
      if (skill.at(i) < X){
        break;
      }
      else if (i == M-1){
        if (price < Min){
          Min = price;
        }
      }
    }
  }
  
  cout << Min << endl;
}

  