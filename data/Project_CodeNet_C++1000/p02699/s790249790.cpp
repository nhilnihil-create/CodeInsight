#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int s,w;
  cin >> s >> w;
  if(s<=w){
    cout << "unsafe" <<endl;
  }
  else{
    cout << "safe" <<endl;
  }
  return 0;
}