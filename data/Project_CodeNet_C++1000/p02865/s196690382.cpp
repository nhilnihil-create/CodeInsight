#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>

using namespace std;
const long long P = 1000000007;

int main() {
  int n;
  cin >> n;
  int count = 0;
  for(int i = 1; i < n; i++) {
    if(n-i != i) {
      count++;
    }
  }
  cout << count/2 << endl;
  return 0;
}
