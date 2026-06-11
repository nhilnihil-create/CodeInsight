#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, K, Q, A;
  cin >> N >> K >> Q;
  vector<int> V(N, 0);
  for (int i=0; i<Q; i++) {
    cin >> A;
    V[A-1]++;
  }
  for (int i=0; i<N; i++) {
    if (Q-V[i]>=K) {
      cout << "No" << endl;
    }
    else {
      cout << "Yes" << endl;
    }
  }
}