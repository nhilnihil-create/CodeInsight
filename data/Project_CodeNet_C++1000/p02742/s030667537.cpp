#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2) // 2進数の文字列を int に

int main() {
  ll H, W;
  cin >> H >> W;
  if (W == 1 || H == 1)
    cout << 1 << endl;
  else
    cout << (H / 2) * (W / 2) + (H%2==0 ? H / 2 : (H / 2 + 1)) * (W%2==0 ? W / 2 : (W / 2 + 1)) << endl;
}
