#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h1,h2,m1,m2,k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int t = (h2-h1)*60+m2-m1;
  cout << t-k << endl;
}