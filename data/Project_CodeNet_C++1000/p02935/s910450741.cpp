#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  double ans = 0.00;
  vector<int>value(N);
  for(int i=0; i<N; i++) cin >> value.at(i);
  
  sort(value.begin(), value.end());
  ans = value.at(0);
  for(int i=0; i<N; i++){
    ans = (ans + value.at(i))/2;
  }
  cout << ans << endl;
}