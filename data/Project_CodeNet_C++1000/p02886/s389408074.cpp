#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, ans=0;
  cin >> N;
  vector<int> d(N);
  for(int i=0; i<N; i++) cin >> d.at(i);
  
  for(int i=0; i<N; i++) {
    for(int j=i+1; j<N; j++) {
      ans += d.at(i)*d.at(j);
    }
  }
  
  cout << ans << endl;
  
}