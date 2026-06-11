#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2) // 2進数の文字列を int に
//cout << fixed << setprecision(15);

int main() {
  int N, M;
  cin >> N >> M;
  int ac = 0, wa = 0;
  vi w(N);
  vb finished(N);
  rep(i, M) {
    int p;
    string S;
    cin >> p >> S;
    if(finished[p])
      continue;
    if(S == "AC") {
      ac++;
      finished[p] = true;
      wa += w[p];
    }
    else {
      w[p]++;
    }
  }
  cout << ac << " " << wa << endl;
}