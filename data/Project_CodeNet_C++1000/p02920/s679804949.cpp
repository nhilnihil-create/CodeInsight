#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


using pqi = priority_queue<int>;

bool fueru(pqi& pq1, pqi& pq2) {
  pqi npq1, npq2;
  // cerr << pq1.size() << " " << pq2.size() << endl;
  while (!pq1.empty()) {
    int from = pq1.top(); pq1.pop();
    npq1.push(from);
    bool found = false;
    while (!pq2.empty()) {
      int to = pq2.top(); pq2.pop();
      if (to < from) { 
        found = true;
        npq1.push(to);
        break;
      }
      npq2.push(to);
    }
    if (!found) return false;
  }
  swap(pq1, npq1);
  while (!npq2.empty()) {
    pq2.push(npq2.top()); npq2.pop();
  }
  return true;
}

int main() {
  int n; cin >> n;
  pqi pq1, pq2;
  for (int i = 0; i < (1<<n); ++i) {
    int s; cin >> s;
    pq2.push(s);
  }
  pq1.push(pq2.top()); pq2.pop();
  for (int i = 0; i < n; ++i) {
    if (!fueru(pq1, pq2)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
