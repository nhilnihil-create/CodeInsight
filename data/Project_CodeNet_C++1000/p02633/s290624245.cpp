#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int X;
  cin >> X;
  vector<int> k(360);
  for (int i=0; i<360; i++) {
    k[i]=5000;
  }
  for (int j=0; j<360; j++) {
    if (((j+1)*X)%360==0) {
      k[j]=j+1;
    }
  }
  sort(k.begin(),k.end());
  cout << k[0] << endl;
}