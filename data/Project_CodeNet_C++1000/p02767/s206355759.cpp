#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int sum;
  int m;
  cin >> N;
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }

  int min = *min_element(vec.begin(), vec.end());
  int max = *max_element(vec.begin(), vec.end());


  for (int i = min; i <= max; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      sum += pow(vec[j] - i, 2.0);
    }
    if (i == min) m = sum;
    if (sum < m) m = sum;
  }

  cout << m << endl;
}