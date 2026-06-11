#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  int ball[k];
  n = n-k;
  ball[0] = 1;
  ball[k-1] = 1+n;
  cout << ball[k-1]-ball[0] << endl;
  return 0;
}
