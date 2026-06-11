#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> C(N);
  for(int i= 0; i<K;i++){
    int d;
    cin >> d;
    for(int j = 0;j<d;j++){
      int a;
      cin >> a;
      --a;
      ++C[a];
    }
  }
  int ans = count(C.begin(), C.end(),0);
  cout << ans << endl;
}