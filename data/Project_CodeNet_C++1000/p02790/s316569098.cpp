#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll A,B;
  cin >> A >> B;
  string s1(A, '0'+B);
  string s2(B, '0'+A);
  if (s1 < s2) {
    cout << s1 << endl;
  } else {
    cout << s2 << endl;
      }

}

