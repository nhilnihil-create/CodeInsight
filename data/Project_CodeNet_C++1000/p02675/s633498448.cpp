#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  int x = N%10;
  if(x == 2 || x == 4 || x == 5 || x == 7 || x == 9)
    cout << "hon" << endl;
  else if(x == 0 || x == 1 || x == 6 || x == 8)
    cout << "pon" << endl;
  else
    cout << "bon" << endl;
  return 0;
}