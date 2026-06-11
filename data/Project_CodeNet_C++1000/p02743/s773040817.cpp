#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2) // 2進数の文字列を int に

int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  ll d = c - a - b;
  cout << (0 < d && 4 * a * b < d * d ? "Yes" : "No") << endl;
}
