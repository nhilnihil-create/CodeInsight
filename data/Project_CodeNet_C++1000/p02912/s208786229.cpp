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
  int N,M;
  cin >> N >> M;
  priority_queue<int> A;
  for(int i = 0;i < N;i++){
    int a;
    cin >> a;
    A.push(a);
  }
  for(int i = 0;i < M;i++){
    int x = 0;
    x = A.top();
    A.pop();
    A.push(x/2);
  }
  long long ans = 0;
  for(int i = 0;i < N;i++){
    int xx = A.top();
    ans += xx;
    A.pop();
  }
  cout << ans << endl;
}
