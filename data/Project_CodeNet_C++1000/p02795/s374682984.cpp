#include <bits/stdc++.h>
using namespace std;
int main(){
  int H, W, N;
  cin >> H >> W >> N;
  if (H > W){
    cout << (N + H - 1) / H;
  } else {
    cout << (N + W - 1) / W;
  }
}