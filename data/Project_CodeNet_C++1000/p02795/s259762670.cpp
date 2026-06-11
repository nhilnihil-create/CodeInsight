#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  if (H>=W) {
    if (N%H==0) {
      cout << N/H << endl;
    }
    else {
      cout << 1+(N-(N%H))/H << endl;
    }
  }
  else {
    if (N%W==0) {
      cout << N/W << endl;
    }
    else {
      cout << 1+(N-(N%W))/W << endl;
    }
  }
}