#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  vector<int> vec(n);
  int total = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    vec.at(i) = x;
  }
  
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      total += vec.at(i) * vec.at(j);
    }
  }
  
  cout << total << endl;
  
}