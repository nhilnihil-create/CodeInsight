#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> weight(N);
  int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> weight.at(i);
    sum += weight.at(i);
  }
  int total = 0;
  for(int i = 0; i < N - 1; i++) {
    total += weight.at(i);
    if(2 * total >= sum) {
      cout << min(2 * total - sum, sum - 2 * (total - weight.at(i))) << endl;
      return 0;
    }
  }
  cout << sum - 2 * total << endl;  
}