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
  int N = 0,K = 0;
  cin >> N >> K;
  string s;
  cin >> s;
  int ans = 0;
  for(int i = 0;i < N - 1;i++){
    if(s.at(i) == s.at(i + 1)){
      ans++;
    }
  }
  ans = min(ans+2*K,N - 1);
  cout << ans << endl;
}
