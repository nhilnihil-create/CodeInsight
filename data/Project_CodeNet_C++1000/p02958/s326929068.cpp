#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int count = 0;
  
  vector<int>p(N);
  for (int i = 0; i < N; i++) {
    cin >> p.at(i);
    if (p.at(i) != i+1){
      count++;
    }
  }

  if (count == 0 || count == 2){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
  