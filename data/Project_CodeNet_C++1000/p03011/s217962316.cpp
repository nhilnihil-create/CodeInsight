#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int p,q,r;
  cin >> p >>q >> r;
  cout << min({p+q,q+r,r+p}) << endl;
}