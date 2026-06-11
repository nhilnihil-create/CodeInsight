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
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N - 1);
  for(int i = 0;i < N;i++){
    cin >> A.at(i);
    A.at(i) -= 1;
  }
  for(int i = 0;i < N;i++){
    cin >> B.at(i);
  }for(int i = 0;i < N - 1;i++){
    cin >> C.at(i);
  }
  int ans = 0;
  int x = 100000;
  for(int i = 0;i < N;i++){
    int now = A.at(i);
    ans += B.at(now);
    if(x == now - 1){
      ans += C.at(x);
    }
    x = now;
  }
  cout << ans << endl;
}
