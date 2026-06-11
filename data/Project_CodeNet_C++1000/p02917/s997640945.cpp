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
  vector<int> B(N - 1);
  for(int i = 0;i < N - 1;i++){
    cin >> B.at(i);
  }
  vector<int> A(N);
  A.at(0) = B.at(0);
  for(int i = 1;i < N - 1;i++){
    A.at(i) = min(B.at(i - 1),B.at(i));
  }
  A.at(N - 1) = B.at(N - 2);
  long long ans = 0;
  for(int i = 0;i < N;i++){
    ans += A.at(i);
  }
  cout << ans << endl;
}
