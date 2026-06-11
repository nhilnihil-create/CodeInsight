#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll A,B;
  cin >> A >> B;
  unordered_set<int> s;
  s.emplace(1);
  s.emplace(2);
  s.emplace(3);
  s.erase(A);
  s.erase(B);
  cout << *s.begin() << endl;
  

}
