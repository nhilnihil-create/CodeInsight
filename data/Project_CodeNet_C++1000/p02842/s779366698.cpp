#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> vec(46300);
  for (int i = 0; i < 46300; i++) {
    vec.at(i) = i*1.08;
  }
  
  for (int i = 0; i < 46300; i++) {
    if (vec.at(i) == N){
      cout << i << endl;
      break;
    }
    else if (vec.at(i) > N){
      cout << ":(" << endl;
      break;
    }
  }
}
  