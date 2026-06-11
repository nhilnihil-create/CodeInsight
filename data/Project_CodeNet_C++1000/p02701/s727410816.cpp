#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<string, int> kinds;
  for(int i=0;i<n;i++) {
    string s;
    cin >> s;
    kinds[s]++;
  }
  cout << kinds.size() << "\n";
}
