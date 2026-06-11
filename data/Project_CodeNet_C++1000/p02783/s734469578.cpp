#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int h, a;
  cin >> h >> a;
  int atk_t = 0;
  if(h % a == 0) atk_t = h / a;
  else atk_t = (h / a) + 1;
  
  cout << atk_t << endl;
  return 0;
}