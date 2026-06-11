#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N; cin >> N;
  vector<double> v(N);
  for (int i = 0; i < N; i++) cin >> v.at(i);
  sort(v.begin(), v.end());
  while(v.size() > 1) {
    double new_v = (v[0] + v[1])/2;
    v.erase(v.begin());
    v[0] = new_v;
  }
  cout << v[0] << endl;
  return 0;
}