#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int M = 1e7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  string t;
  cin >> t;

  rep(i,t.size()) if (t[i] == '?') t[i] = 'D';
  cout << t << endl;

  return 0;
}
