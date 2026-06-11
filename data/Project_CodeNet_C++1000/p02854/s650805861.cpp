#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  
  vector<ull> ai;
  
  ull sum = 0;
  
  while (n--) {
    ull k;
    cin >> k;
    
    sum += k;
    
    ai.pb(k);
  }
  
  ull res = 2020202020*200000;
  
  ull ls = 0;

  for (ull i = 0; i < ai.size(); ++i) {
    ls += ai.at(i);
    ull rs = sum-ls;
    
    res = min(res, max(ls, rs) - min(ls, rs));
  }
  
  cout << res << endl;
  return 0;
}