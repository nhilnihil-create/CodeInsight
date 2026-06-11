#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> data(n);
  for(int i = 0; i < n; i++) {
    cin >> data.at(i);
  }
  int count = 0;
  for(int i = 1; i < n - 1; i++) {
    if(data.at(i - 1) < data.at(i) && data.at(i) < data.at(i + 1)) {
      count++;
    }
    else if(data.at(i - 1) > data.at(i) && data.at(i) > data.at(i + 1)) {
      count++;
    }
  }
  cout << count << endl;
}