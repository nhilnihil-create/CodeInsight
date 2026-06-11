#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2) // 2進数の文字列を int に
 
int main() {
  ll A, B;
  cin >> A >> B;
  REP(i, 90000) {
    if ((int) (i * 0.08) == A && (int) (i * 0.1) == B) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}