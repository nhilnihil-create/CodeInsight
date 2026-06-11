#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  cin >> n >> k;
  int m=1;
  int i =0;
  while(n/m>0) {
    m *= k;
    i++;
  }
  cout << i << endl;
}