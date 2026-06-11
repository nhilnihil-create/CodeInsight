#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int M = 1e7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  int n;
  cin >> n;

  if (n%2 == 0) cout << n / 2 - 1 << endl;
  else cout << (n+1) / 2 - 1<< endl;

  return 0;
}
