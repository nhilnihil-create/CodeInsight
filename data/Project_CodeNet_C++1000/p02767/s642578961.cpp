#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int x[n];
  for (int i=0; i<n; i++) {
    cin >> x[i];
  }
  int mini = -1;
  for (int i=0; i<100; i++) {
    int sum = 0;
    for (int j=0; j<n; j++) {
      sum += (i+1-x[j])*(i+1-x[j]);
    }
    if (sum < mini || mini == -1) {
      mini = sum;
//      cout << sum << endl;
    }
  }
  cout << mini << endl;
}


