#include <bits/stdc++.h>
using namespace std;

int main() {
  //宣言と入力、違いの和
  int N,tigai=0;
  cin >> N;
  vector<int>p(N);
  vector<int>tadasii(N);
  for(int i=0; i<N; i++){
    cin >> p[i];
    tadasii[i] = i+1;
    if(p[i] != tadasii[i]){
      tigai++;
    }
  }
  //判断、出力
  if(tigai == 0 || tigai == 2){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}
