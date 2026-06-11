#include <bits/stdc++.h>
using namespace std;

vector<long long> h;

long long parent(int n){
  if(n/2 == 0) return numeric_limits<long long>::min();
  return h[n/2];
}

long long left(int n){
  int l = n*2;
  if(l >= h.size()) return numeric_limits<long long>::min();
  return h[l];
}
long long right(int n){
  int r = n*2+1;
  if(r >= h.size()) return numeric_limits<long long>::min();
  return h[r];
}

int main() {
  int n; cin >> n;

  h.resize(n+1);
  for(int i=1; i<=n; ++i) cin >> h[i];

  for(int i=1; i<=n; ++i){
    cout << "node " << i << ": " << "key = " << h[i] << ", ";
    long long p = parent(i), l = left(i), r = right(i);
    if(p != numeric_limits<long long>::min()) cout << "parent key = " << p << ", ";
    if(l != numeric_limits<long long>::min()) cout << "left key = " << l << ", ";
    if(r != numeric_limits<long long>::min()) cout << "right key = " << r << ", ";
    cout << endl;
  }
}

