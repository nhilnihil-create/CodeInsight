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
  long long N = 0,K = 0,Q = 0;
  cin >> N >> K >> Q;
  vector<long long> person(N);
  for(int i = 0;i < N;i++){
    person.at(i) = K - Q;
  }
  int x;
  for(int i = 0;i < Q;i++){
    cin >> x;
    person.at(x - 1) += 1;
  }
  for(int i = 0;i < N;i++){
    if(person.at(i) > 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}
