#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)


int main() {
  int n;
  cin >> n;
  vector<int> vec(n),vecori;
  REP(i,n) cin >> vec[i];
  copy(vec.begin(),vec.end(),back_inserter(vecori));
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  int f = vec[0];
  int s = vec[1];
  int ans = f;
  REP(i,n){
    ans = f;
    if(vecori[i] == f)ans = s;
    cout << ans << endl;
  }

}