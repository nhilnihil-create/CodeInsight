#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  string N;
  cin >> N;
  int p = 0;
  rep(i,N.size()){
    p += int(N.at(i))-48;
    p %= 9;
  }
  if(p == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}