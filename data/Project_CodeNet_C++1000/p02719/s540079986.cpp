#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, K; 
  cin >> N >> K; 

  vector<int64_t> tmp; 
  tmp.push_back(abs(N%K - K)); 
  tmp.push_back(N%K); 
  cout << *min_element(tmp.begin(), tmp.end()); 

  return 0;
}
