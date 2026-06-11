#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  if(s.find("R")!=-1) ans = 1;
  if(s.find("RR")!=-1) ans = 2;
  if(s.find("RRR")!=-1) ans = 3;
  cout << ans << endl;
}
