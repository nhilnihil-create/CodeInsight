#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> F(6);
  for (int i = 0; i < 6; i++){
    cin >> F[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int t, f;
    cin >> t >> f;
    for (int j = 0; j < 6; j++){
      if (t == F[j]){
        t = j;
        break;
      }
    }
    for (int j = 0; j < 6; j++){
      if (f == F[j]){
        f = j;
        break;
      }
    }
    int r;
    if (t == 0 && f == 1) r = 2;
    if (t == 0 && f == 2) r = 4;
    if (t == 0 && f == 3) r = 1;
    if (t == 0 && f == 4) r = 3;
    if (t == 1 && f == 0) r = 3;
    if (t == 1 && f == 2) r = 0;
    if (t == 1 && f == 3) r = 5;
    if (t == 1 && f == 5) r = 2;
    if (t == 2 && f == 0) r = 1;
    if (t == 2 && f == 1) r = 5;
    if (t == 2 && f == 4) r = 0;
    if (t == 2 && f == 5) r = 4;
    if (t == 3 && f == 0) r = 4;
    if (t == 3 && f == 1) r = 0;
    if (t == 3 && f == 4) r = 5;
    if (t == 3 && f == 5) r = 1;
    if (t == 4 && f == 0) r = 2;
    if (t == 4 && f == 2) r = 5;
    if (t == 4 && f == 3) r = 0;
    if (t == 4 && f == 5) r = 3;
    if (t == 5 && f == 1) r = 3;
    if (t == 5 && f == 2) r = 1;
    if (t == 5 && f == 3) r = 4;
    if (t == 5 && f == 4) r = 2;
    cout << F[r] << endl;
  }
}
