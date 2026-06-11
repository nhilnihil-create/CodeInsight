#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>

const ll INF = pow(10, 9) + 7;

int main() {
  int a,b;
  cin >> a >> b;
  if(a<=2*b) cout << 0 << endl;
  else cout << a-2*b << endl;
}