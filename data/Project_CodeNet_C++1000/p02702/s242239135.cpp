#include <iostream>
#include <map>
#include <string>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define i64 long long

using namespace std;

string n;
int d;
i64 b = 1, s, ans;
map<i64, i64> f;

int main() {_
  cin >> n;
  reverse(n.begin(), n.end());
  f[0] = 1;
  for(char c : n) {
  	d = c - '0';
    s = (s + d*b)%2019;
    b = 10*b % 2019;
    ans += f[s];
    ++f[s];
  }
  cout << ans << endl;                        
}