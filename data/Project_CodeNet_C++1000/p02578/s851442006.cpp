#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> arr;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  long long sum = 0;
  int max_value = 0;
  int Bi = 0;
  for (int i = 0; i < arr.size(); ++i) {
    max_value = max(max_value, arr[i]);
    Bi = max_value;
    sum += (Bi - arr[i]);
  }
  cout << sum << endl;
}