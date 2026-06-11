#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int counter = 0;
  for(int i = 0; i < n; i += 2) {
    if(v[i] % 2 == 1) {
      counter++;
    }
  }
  cout << counter << '\n';
}
