#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long N;
  cin >> N;

  vector<long> d(N);
  for (long i=0; i<N; i++) {
    cin >> d.at(i);
  }
  
  //sortして、中間の値の間にいくつ数値が入るかを調べる
  sort(d.begin(), d.end());
  long diff = d.at(d.size()/2)-d.at(d.size()/2-1);
  
  cout << diff << endl;
  
  return 0;
}