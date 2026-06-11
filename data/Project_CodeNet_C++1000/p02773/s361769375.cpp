#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N; map<string,int> mapS; int countMax =0;
  for (int i =0; i<N; i++) {string s; cin >> s; mapS.count(s)? mapS.at(s)++ : mapS[s] = 1;}
  for (auto x : mapS) countMax = max(x.second,countMax);
  for (auto x : mapS) if (x.second == countMax) cout << x.first << endl;
}