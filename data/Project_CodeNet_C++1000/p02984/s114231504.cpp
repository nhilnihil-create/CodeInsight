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
  vector<int> rain(N);
  int S = 0;
  for(int i = 0;i < N;i++){
    cin >> rain.at(i);
    S += rain.at(i);
  }
  int X = S;
  for(int i = 1;i <= N - 1;i++){
    X = X - 2*rain.at(i);
    i++;
  }
  cout << X;
  int XX;
  for(int i = 1;i < N;i++){
    XX = 2*rain.at(i - 1) - X;
    cout << " " << XX;
    X = XX;
  }
  cout << endl;
}
