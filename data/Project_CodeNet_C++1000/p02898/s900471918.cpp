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
  int N,K;
  cin >> N >> K;
  int count = 0;
  for(int i = 0;i < N;i++){
    int x;
    cin >> x;
    if(x >= K){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
