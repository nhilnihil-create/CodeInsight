#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,M,SUM;
  cin >> N >> M;
  SUM=0;
  vector<int> a(M);
    for (int i = 0 ;i<M;i++){
      cin >> a.at(i);
      SUM=SUM+a.at(i);
    }
    if(SUM>N){
      cout << -1 << endl;
    }
    else {
      cout << N-SUM << endl;
    }
    return 0;
}