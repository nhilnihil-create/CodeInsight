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
  vector<int> box(N);
  int X = 0,count = 0,countx = 0;
  for(int i = 0;i < N;i++){
    cin >> box.at(i);
    count = max(count,box.at(i));
    if(count != countx){
      X = i;
    }
    countx = count;
  }
  int countt = 0;
  for(int i = 0;i < N;i++){
    if(i != X){
      countt = max(countt,box.at(i));
    }
  }
  for(int i = 0;i < N;i++){
    if(i != X){
      cout << count << endl;
    }else{
      cout << countt << endl;
    }
  }
}
