#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> P(N, "WA");
  vector<int> V(N, 0);
  int p;
  string S;
  for (int i=0; i<M; i++) {
    cin >> p >> S;
    if (P[p-1]=="WA") {
      if (S=="WA") {
        V[p-1]++;
      }
      else {
        P[p-1]=S;
      }
    }
  }
  
  int ac=0, pn=0;
  for (int i=0; i<N; i++) {
    if (P[i]=="AC") {
      ac++;
      pn+=V[i];
    }
  }
  cout << ac << " " << pn << endl;
}