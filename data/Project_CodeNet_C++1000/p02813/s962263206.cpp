#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N), Q(N), V(N);
  for(int i=0; i<N; i++) {
    cin >> P[i];
  }
  for(int i=0; i<N; i++) {
    cin >> Q[i];
  }
  for(int i=0; i<N; i++) {
    V[i]=i+1;
  }
  
  int i=1, a, b;
  do {
    if (V==P) {
      a=i;
    }
    if (V==Q) {
      b=i;
    }
    i++;
  } while(next_permutation(V.begin(), V.end()));
  cout << abs(a-b) << endl;
}