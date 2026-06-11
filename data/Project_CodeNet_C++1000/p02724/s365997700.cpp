#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int X;
  cin >> X;

  int a = X / 500 * 1000;
  int b = X % 500 / 5 * 5;

  cout << a + b << endl;
}
