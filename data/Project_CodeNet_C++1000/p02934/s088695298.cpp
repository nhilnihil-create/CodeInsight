#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
using namespace std;

int main(){
  int N;
  cin >> N;
  double ans = 0.0,a;
  for(int i = 0;i < N;i++){
    cin >> a;
    ans += 1.0/a;
  }
  ans = 1.0/ans;
  cout << fixed << setprecision(16) << ans << endl;
}
