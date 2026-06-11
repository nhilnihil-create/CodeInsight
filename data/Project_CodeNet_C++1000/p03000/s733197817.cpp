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
  int N,X;
  cin >> N >> X;
  vector<int> bound(N);
  for(int i = 0;i < N;i++){
    cin >> bound.at(i);
  }
  int D = 0;
  int DD;
  int count = 1;
  for(int i = 1;i <= N;i++){
    DD = D + bound.at(i - 1);
    D = DD;
    if(DD <= X){
      count++;
    }else{
      break;
    }
  }
  cout << count << endl;
}
