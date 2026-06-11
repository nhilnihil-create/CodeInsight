#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  int cmp = n;
  do {
    cnt++;
    cmp /= k;
  }while(cmp > 0);
  
  cout << cnt << endl;
  return 0;
}