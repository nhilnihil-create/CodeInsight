#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
#include <string>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)
#pragma GCC optimize("unroll-loops")

#define DEBUG(x) cout << ">> " << #x << ": " << x << endl;
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f first
#define s second

const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int main() { _
  string s; cin >> s;
  if (s.size() & 1) cout << "No" << endl;
  else {
    bool fail = false;
    for (int i = 0; i < s.size(); i += 2) {
      if (s[i] != 'h' || s[i+1] != 'i') {
        fail = true;
        break;
      }
    }
    if (fail) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  return 0;
}