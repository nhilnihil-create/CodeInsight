#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2) // 2進数の文字列を int に
//cout << fixed << setprecision(15);

int main() {
  int H, N;
  cin >> H >> N;
  int t, sum = 0;
  REP(i, N) {
    cin >> t;
    sum += t;
  }
  cout << (H <= sum ? "Yes" : "No") << endl;
}