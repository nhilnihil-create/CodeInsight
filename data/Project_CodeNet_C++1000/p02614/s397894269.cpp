#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<int>> V0(H, vector<int>(W, 0));
  char D;
  char B = '#';
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> D;
      if (D == B) {
        V0.at(i).at(j) = 1;
      }
      else {
        V0.at(i).at(j) = 0;
      }
    }
  }

  int C = 0;
  
  for (int i = 0; i < pow(2, H + W); i++) {
    vector<vector<int>> V = V0;
    int I = i;
    vector<int> E(H + W, 1);
    for (int j = H + W - 1; j >= 0; j--) {
      int p = pow(2, j);
      if (I >= p) {
        I -= p;
        E.at(j) = 0;
      }
    }
    
    /*
    for (int ll = 0; ll < H + W; ll++) {
      cout << E.at(ll) << " ";
    }
    cout << endl;
    */
    
    for (int k = 0; k < H + W; k++) {
      if (E.at(k) == 1) {continue;}
      if (k < H) {
        for (int l = 0; l < W; l++) {
          V.at(k).at(l) *= 0;
        }
      }
      else {
        for (int l = 0; l < H; l++) {
          V.at(l).at(k - H) *= 0;
        }
      }
    }
  
    int sum = 0;
    for (int k = 0; k < H; k++) {
      for (int j = 0; j < W; j++) {
        sum += V.at(k).at(j);
      }
    }
    //cout << sum << endl;
    if (sum == K) {
      C++;
    }
  }
  cout << C << endl;
}
