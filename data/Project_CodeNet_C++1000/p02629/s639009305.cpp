#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

string f(ll n){
  if (n == 0) return "";
  n--;
  return f(n / 26) + char('a' + n % 26);
}

int main(void){
  ll N;
  cin >> N;

  cout << f(N) << endl;
}
