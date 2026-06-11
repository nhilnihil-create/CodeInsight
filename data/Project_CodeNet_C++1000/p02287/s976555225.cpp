#include <bits/stdc++.h>
using namespace std;

long long h;
vector<long long> v;

int main() {
  cin >> h;
  v.resize(h + 1);
  for(int i = 0; i < h; ++i) cin >> v[i + 1];
  for(int i = 0; i < h; ++i) {
    int id = i + 1;
    cout << "node " << id << ": key = " << v[id] << ", ";
    if(id > 1) cout << "parent key = " << v[id / 2] << ", ";
    if(id * 2 <= h)
      cout << "left key = " << v[id * 2] << ", ";
    if(id * 2 < h)
      cout << "right key = " << v[id * 2 + 1] << ", ";
    cout << endl;
  }

  return 0;
}
