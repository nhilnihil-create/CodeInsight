#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  cout << min(a+b,min(b+c,c+a)) << endl;
  return 0;
}