#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  vector<int64_t> d(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> d.at(i);
  }

  sort(d.begin(), d.end()); 

  int64_t c = N / 2; 
  cout << d.at(c) - d.at(c-1); 

  return 0;
}
