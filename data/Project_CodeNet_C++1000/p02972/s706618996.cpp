#include<bits/stdc++.h>
using namespace std;

int N;
int a[200001];

signed main() {
  cin >> N; 
  for(int i=1; i<=N; i++) cin >> a[i];

  vector<int> b(N+1, 0);
  int M = 0;
  set<int> bi;

  for(int i=N; i>0; i--) {
    if(i*2>N) {
      b[i] = a[i];
      M += b[i];
      if(b[i]) bi.insert(i);
      continue;
    }

    int sum = 0;
    for(int j=i*2; j<=N; j+=i) sum += b[j];
    sum %= 2;
    b[i] = a[i] ^ sum;
    if(b[i]) bi.insert(i);
    M += b[i];
  }

  cout << M << endl;
  for(auto i : bi) {
    cout << i << " ";
  }
  cout << endl;
}
