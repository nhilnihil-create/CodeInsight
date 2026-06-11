#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, p;
  cin >> N;
  vector<pp> V(N);
  for (int i=0; i<N; i++) {
    cin >> p;
    V[i]=pp(p,i);
  }
  sort(V.begin(), V.end());
  for (int i=0; i<N; i++) {
    cout << V[i].second+1;
    if (i==N-1) {break;}
    cout << " ";
  }
  cout << endl;
}