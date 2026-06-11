#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  int K;
  string S;
  cin >> K >> S;
  //長さがK以下ならそのままSを出力
  //K以上なら...と出力
  for(int i = 0; i < S.size(); i++){
    if(i < K){
      cout << S.at(i);
    }else{
      cout << "..." << endl;
      return 0;
    }
  }





}
