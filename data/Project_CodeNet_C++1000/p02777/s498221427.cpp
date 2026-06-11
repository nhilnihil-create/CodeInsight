#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> v;
  string a,b,c;
  cin >> a >> b;
  cin >> v[a] >> v[b];
  cin >> c;
  v[c]--;
  cout << v[a] << " " << v[b] << endl;
}