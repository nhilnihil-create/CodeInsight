#include <iostream>
#include <bits/stdc++.h>

#define REP(i, n) for(int i=0; i<n; i++)

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<int> v;
  int x;

  while(true) {
    std::cin >> x;
    if(x != 0) v.push_back(x);
    else break;
  }

  int count[v.size()];

  REP(i, v.size()) {
    count[i] = 0;
    for(int j=1; j<=v[i]/2; j++) {
      int sum = 0;
      for(int k=j; sum<v[i]; k++) {
        sum += k;
        if(sum == v[i]) count[i]++;
      }
    }
  }

  REP(i, v.size()) std::cout << count[i] << '\n';
}

