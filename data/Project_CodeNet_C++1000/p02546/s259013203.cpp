#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e18;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  string s;
  cin >> s;
  if(s.back() == 's') {
    s.push_back('e');
    s.push_back('s');
  } else {
    s.push_back('s');
  }
  cout << s << endl;
  return 0;
}
