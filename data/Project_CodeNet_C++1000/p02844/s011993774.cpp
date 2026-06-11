# include <iostream>
# include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  std::cin >> n;
  char S[n];
  std::cin >> S;
  char origin[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  vector<vector<char>> data(1000, vector<char>(4));
  int ii = 0;
  for (int i=0; i < 10; i++){
    for (int j=0; j < 10; j++){
      for (int h=0; h < 10; h++){
        data.at(ii).at(0) = origin[i];
        data.at(ii).at(1) = origin[j];
        data.at(ii).at(2) = origin[h];
        ++ii;
      }
    }
  }
  int cnt = 0;
  vector<char> ans = vector<char>(3);
  for (int i=0; i<1000; i++) {
    ans = data.at(i);
    int f_flg=0, s_flg=0, t_flg=0;
    for (int j=0; j<n; j++) {
      if (!f_flg) {
        if (S[j] == ans.at(0)) {
          f_flg = 1;
        }
        continue;
      } else if (!s_flg) {
        if (S[j] == ans.at(1)){
          s_flg = 1;
        }
        continue;
      } else if (S[j] == ans.at(2)) {
        cnt++;
        break;
      }
    }
  }
  // char[3] ans[1000];
  // for ( int i=0;i<1000;i++){
  //   
  // }
  std::cout << cnt << std::endl;
  return 0;
}
