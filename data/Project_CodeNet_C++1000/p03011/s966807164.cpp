#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> flights(3);
  for (int i = 0; i < 3; ++i) {
    cin >> flights[i];
  }
  sort(flights.begin(), flights.end());
  
  cout << flights[0] + flights[1] << endl;
  
  return 0;
}
