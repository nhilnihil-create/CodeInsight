#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int ta[100];
int ha[100];


void solve() {
  int sumTa, sumHa;
  sumTa= sumHa = 0;
  for(int i = 0; i < n; ++i) sumTa += ta[i];
  for(int i = 0; i < m; ++i) sumHa += ha[i];
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      sumTa -= ta[i];
      sumHa += ta[i];
      sumHa -= ha[j];
      sumTa += ha[j];
      if(sumTa == sumHa) {
	cout << ta[i] << " " << ha[j] << endl;
	return;
      }
      sumTa += ta[i];
      sumHa -= ta[i];
      sumHa += ha[j];
      sumTa -= ha[j];
    }
  }
  cout << -1 << endl;
}

main() {
  while((cin >> n >> m) && (n || m)) {
    for(int i = 0; i < n; ++i) {
      cin >> ta[i];
    }
    for(int i = 0; i < m; ++i) {
      cin >> ha[i];
    }
    solve();
  }
}