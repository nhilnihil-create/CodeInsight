#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)    for (int i=(a)  ;i<(b) ;i++)
#define RFOR(i,a,b)   for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)      for (int i=0    ;i<(n) ;i++)
#define RREP(i,n)     for (int i=(n)-1;i>=0  ;i--)
#define EACH(i,a,b)   for (int i=(a)  ;i<=(b);i++)
#define REACH(i,a,b)  for (int i=(b)  ;i>=(a);i--)
#define ALL(a)        (a).begin(),  (a).end()
#define RALL(a)       (a).rbegin(), (a).rend()

const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const double EPS = 1e-10;

using ll = long long;
using P = pair<int,int>;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  vector<int> A(9);
  REP(i,9)
    cin >> A[i];

  cin >> N;
  vector<bool> hit(9,false);
  int b;
  REP(i,N) {
    cin >> b;
    auto it = find(ALL(A), b);
    auto n = distance(A.begin(), it);
    if (n != 9) hit[n] = true;
  }

  bool ans = hit[0] && hit[1] && hit[2]
    || hit[3] && hit[4] && hit[5]
    || hit[6] && hit[7] && hit[8]
    || hit[0] && hit[3] && hit[6]
    || hit[1] && hit[4] && hit[7]
    || hit[2] && hit[5] && hit[8]
    || hit[0] && hit[4] && hit[8]
    || hit[2] && hit[4] && hit[6];

  cout << (ans ? "Yes" : "No") << endl;

  return 0;
}

