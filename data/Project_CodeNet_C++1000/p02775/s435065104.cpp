#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin >> s;
  int n = 0;
  n = s.size();
  vector<int> up(n);
  vector<int> notup(n);
  up[n - 1] = 10 - (s[n - 1] - '0');
  notup[n - 1] = s[n - 1] - '0';
  for(int i = n - 2;i >= 0;i--){
    int now = 0;
    now = s[i] - '0';
    up[i] = min(10 - (now + 1) + up[i + 1],10 - now + notup[i + 1]);
    notup[i] = min(now + 1 + up[i + 1],now + notup[i + 1]);
  }
  int res = 0;
  res = min(up[0] + 1,notup[0]);
  cout << res << endl;
  return 0;
}