#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, N, a;
  int u, l;
  cin >> X >> N;
  vector<int> vec(102);
  for (int i = 0; i < 102; i++) {
    vec.at(i)=0;
  }
  for (int i = 1; i < N+1; i++) {
    cin >> a;
    vec.at(a)=1;
  }
  if (vec.at(X)==0){
    cout << X << endl;
  }
  else{
    for (int i=X+1; i < 102; i++){
      if (vec.at(i)==0){
        u=i;
        break;
      }
    }
    for (int i=X-1; i >= 0; i--){
      if (vec.at(i)==0){
        l=i;
        break;
      }
    }
    if (u-X < X-l)
      cout << u << endl;
    else
      cout << l << endl;
  }
}