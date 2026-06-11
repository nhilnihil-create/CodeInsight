#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2) // 2進数の文字列を int に
 
int main() {
  int N, R;
  cin >> N >> R;
  cout << (N <= 10 ? R + 100 * (10 - N) : R) << endl;
}