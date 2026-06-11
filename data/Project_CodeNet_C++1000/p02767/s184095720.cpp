#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {

  int N;
  vector<int> v;
  cin >> N;
  int total = N/2;
  for (int i = 0; i <  N; i++) {
    int t;
    cin >> t;
    total += t;
    v.push_back(t);
  }
  int mid = total/v.size();
  int result = 0;
  for (int i = 0; i < v.size(); i++) {
    result += pow(abs(v[i] - mid),2);
  }
  cout << result;

  return 0;
}
