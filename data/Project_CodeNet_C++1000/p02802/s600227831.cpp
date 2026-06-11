#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n, 0), vv(n, 0);
  rep(i, 0, m) {
    int a;
    cin >> a;
    a--;
    string s;
    cin >> s;
    if(vv[a] == 0) {
      if(s == "AC") vv[a] = 1;
      else v[a]++;
    }
  }
  int sump = 0, suma = 0;
  rep(i, 0, n) {
    if(vv[i] == 1) sump += v[i];
    suma += vv[i];
  }
  cout << suma << " " << sump << "\n";
}