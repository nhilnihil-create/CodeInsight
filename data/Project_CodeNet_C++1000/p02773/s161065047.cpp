#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, string>;

int main() {
  int N;
  cin >> N;
  map<string,int> M;
  set<string> ss;
  string S;
  for (int i=0; i<N; i++) {
    cin >> S;
    M[S]++;
    ss.insert(S);
  }
  vector<string> V(ss.size());
  for (int i=0; i<(int)V.size(); i++) {
    S=*begin(ss);
    ss.erase(S);
    V[i]=S;
  }
  int m=0;
  for (int i=0; i<(int)V.size(); i++) {
    m=max(m, M[V[i]]);
  }
  vector<string> VV;
  for (int i=0; i<(int)V.size(); i++) {
    if (M[V[i]]==m) {VV.push_back(V[i]);}
  }
  sort(V.begin(), V.end());
  for (int i=0; i<(int)VV.size(); i++) {
    cout << VV[i] << endl;
  }
}