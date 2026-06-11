#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll INF = 1e18;
constexpr double PI = 3.14159265358979;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  ll n, a = 1e9;
  cin >> n;  
  cout << "0 0 1000000000 1 " << (a-n%a)%a << " " << n/a+(n%a > 0) << endl;
  return 0;
}