#include <bits/stdc++.h>
using namespace std;

int main() {
  int counter = 0;
  vector<char> data(4);
  for (int i=0; i<4; i++) {
    cin >> data[i];
  }
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      if (data[i]==data[j]) {
        counter++;
      }
    }
  }
  if (counter == 8) {
    cout << "Yes";
  } else {
  cout << "No";
  }
}