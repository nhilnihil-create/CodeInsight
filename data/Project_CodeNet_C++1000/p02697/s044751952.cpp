#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int n, m;
  cin >> n >> m;
  if(n%2 == 0) {
    int start = 1, end = n;
    bool flg = false;
    for(int i = 0; i < m; ++i) {
      cout << start << " " << end << endl;
      start++;
      end--;
      if(!flg && end-start <= n/2) {
        flg = true;
        end--;
      }
    }
  } else {
    int start = 1, end = n;
    for(int i = 0; i < m; ++i) {
      cout << start << " " << end << endl;
      start++;
      end--;
    }
  }
  return 0;
}