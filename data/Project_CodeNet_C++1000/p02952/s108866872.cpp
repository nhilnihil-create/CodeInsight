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
  int count = 0;
  for(int i = 1;i <= N;i++){
    if(1 <= i && i <= 9){
      count++;
    }else if(100 <= i && i <= 999){
      count++;
    }else if(10000 <= i && i <= 99999){
      count++;
    }
  }
  cout << count << endl;
}
