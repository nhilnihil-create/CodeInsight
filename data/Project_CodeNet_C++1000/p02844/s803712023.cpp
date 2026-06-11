#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string.h>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
  long long  n;
  string s = "";
  string ss;
  int ans = 0;

  cin >> n;
  cin >> ss;

  vector<string> cnd(1000);
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      for(int k = 0; k < 10; k++){
        string ii = to_string(i);
        string jj = to_string(j);
        string kk = to_string(k);
        // cout << "---- ii, jj, kk = " << ii << ", " << jj << ", " << kk << endl;

        // string tmp = to_string(i-'0') + to_string(j-'0') + to_string(k-'0');
        //i, j , k からなる文字列（順不同）を作れるか調べる
        int i_ = ss.find(ii); //iが最初に出てくる場所. カウントは0, 1, 2, ...
        if(i_ == string::npos) continue; //見つからなかったら終了
        string tmp = ss;
        tmp.erase(0, i_+1); //iが最初に出てくる場所まで削除した文字列作成
        // cout << "1: tmp = " << tmp << endl;

        int j_ = tmp.find(jj); //jが最初に出てくる場所. カウントは0, 1, 2, ...
        if(j_ == string::npos) continue; //見つからなかったら終了
        tmp.erase(0, j_+1); //iが最初に出てくる場所まで削除した文字列作成
        // cout << "2: tmp = " << tmp << endl;

        int k_ = tmp.find(kk); //jが最初に出てくる場所. カウントは0, 1, 2, ...
        if(k_ == string::npos) continue; //見つからなかったら終了

        //ここまで来たら作成可能パターンなので +1
        ans++;
        // cout << "-- i, j , k = " << i << ", " << j << ", " << k << endl;

      }
    }
  }
  cout << ans << endl;

}
