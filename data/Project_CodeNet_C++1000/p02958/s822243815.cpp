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
  vector<int> p(N);
  for(int i = 0;i < N;i++){
    cin >> p.at(i);
  }
  int count = 0;
  for(int i = 0;i < N;i++){
    if((i + 1) != p.at(i)){
      count++;
    }
  }
  if(count <= 2){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
