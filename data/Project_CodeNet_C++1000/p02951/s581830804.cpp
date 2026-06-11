#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>

const ll INF = pow(10, 9) + 7;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  if(b+c<=a) cout << 0;
  else cout << b+c-a;
}
