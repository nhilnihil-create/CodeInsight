#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, K, ans=0;
  cin >> N >> K;
  vector<int> h(N);
  for(int i=0; i<N; i++) {
    cin >> h.at(i);
    if(h.at(i) >= K) ans++;
  }
   
  cout << ans << endl;
  
}