#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N;
  cin >> N;
  vector<int> B(N);
  for (int i=0; i<N-1; i++) {
    cin >> B[i];
  }
  
  int S=B[0]+B[N-2];
  for (int i=1; i<N-1; i++) {
    S+=min(B[i-1], B[i]);
  }
  cout << S << endl;
}