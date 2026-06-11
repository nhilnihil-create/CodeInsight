#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> itv(N);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    pair<int, int> p(a+b, a-b);
    itv[i] = p;
//    cout << p.first << p.second << endl;
  }
  
  sort(itv.begin(), itv.end());
//  cout << itv[0].first << endl;
  int start = -15000000000;
  int count = 0;
  for (int i = 0; i < N; i++) {
//    cout << start << itv[i].second << endl;
    if (start <= itv[i].second) {
      count++;
      start = itv[i].first;
    }
  }
  
  cout << count << endl;
}