#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<string> S(N);
  for(int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
 
  sort(S.begin(), S.end());
  
  int ans = 1;
  
  for(int i = 0; i < N-1; i++) {
    if(S.at(i+1) != S.at(i)) ans++;
  }
  
  cout << ans << endl;
}