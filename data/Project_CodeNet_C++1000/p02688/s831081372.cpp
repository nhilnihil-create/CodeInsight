#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  set<int> S;
  for (int i=1; i<=N; i++){
    S.insert(i);
  }
  for (int i=0; i<K; i++){
    int d;
    cin >> d;
    for (int j=0; j<d; j++){
      int e;
      cin >> e;
      S.erase(e);
    }
  }
  cout << S.size() << endl;
}