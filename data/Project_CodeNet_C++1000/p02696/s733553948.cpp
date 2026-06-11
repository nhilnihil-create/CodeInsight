#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll a, b, n;
  cin >> a >> b >> n;
  if(b-1 <= n) cout << a*(b-1)/b << endl;
  else cout << a*n/b << endl;
}
