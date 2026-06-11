#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w, n;
  cin >> h >> w >> n;
  if(h < w) swap(h,w);
  cout << (n-1)/h +1 << endl;
}