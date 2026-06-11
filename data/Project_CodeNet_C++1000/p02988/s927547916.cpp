#include <bits/stdc++.h>
using namespace std;

int main() {
  int counter = 0;
  int number;
  cin >> number;
  vector<int> data(number);
  for (int i=0; i<number; i++) {
    cin >> data[i];
  }
  for (int i=1; i<number-1; i++) {
    if (data[i-1] < data[i] && data[i] < data[i+1]) {
      counter++;
    } else if (data[i+1] < data[i] && data[i] < data[i-1]) {
      counter++;
    }
  }
  cout << counter;
}