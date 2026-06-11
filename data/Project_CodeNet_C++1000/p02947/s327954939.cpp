#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<string> s(N);
  for (int i =0; i<N; i++) {
    string a; cin >> a;
    sort(a.begin(),a.end());
    s.at(i) = a;
  }
  
  map<string,int> mapS;
  for (int i =0; i<N; i++) {
    if (mapS.count(s.at(i))) {
      mapS[s.at(i)]++;
    } else {
      mapS[s.at(i)] = 1;
    }
  }
  
  long count =0;
  for (auto x: mapS) {
    long countS = x.second;
    count += (countS * (countS - 1)) / 2;
  }
  cout << count << endl;
}