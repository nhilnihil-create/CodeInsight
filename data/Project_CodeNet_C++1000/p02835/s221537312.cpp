#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  vector<ll> A(3);
  for (auto& _a : A) cin >> _a;
  if (A[0]+A[1]+A[2] >= 22) {
    cout << "bust" << endl;
  } else {
    cout << "win" << endl;
  }
  

}
