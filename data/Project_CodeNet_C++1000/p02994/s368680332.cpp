#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,l;
  cin >> n >> l;
  vector<int> list(n);
  int total=0,j=100000000,p,e;
  for(int i=0; i<n; i++) {
    list.at(i) = l+i;
    total += list.at(i);
    p = abs(list.at(i));
    if(j > p) {
      j = p;
      e = i;
    }
  }
  total -= list.at(e);
  cout << total << endl;
}