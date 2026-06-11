#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++){
    cin >> a.at(i);
  }
  int x = 0;
  for(int i = 0; i < N; i++){
    if(!(a.at(i) == i + 1))x++;
  }
  if(x == 2 || x == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}