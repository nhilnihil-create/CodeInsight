#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i=0; i<N; i++) {
    cin >> p.at(i);
  }
  vector<int> q(N);
  for (int j=0; j<N; j++) {
    q.at(j)=j+1;
  }
  int S=0;
  for (int k=0; k<N; k++) {
    if (p.at(k)!=q.at(k)) {
      S=S+1;
    }
  }
  if (S<=2) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}