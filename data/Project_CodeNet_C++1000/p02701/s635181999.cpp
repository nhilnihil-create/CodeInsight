#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  int N;
  cin>>N;
  set<string> S;
  string p;
  for (int i=0; i<N; i++) {
    cin >> p;
    S.insert(p);
  }
  cout << S.size() << endl;
}