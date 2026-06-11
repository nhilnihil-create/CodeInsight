#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) a[i] = 0;

  REP(i,n-1){
    int x; cin >> x;
    --x;
    a[x]++;
  }

  for(auto x: a) cout << x << endl;
  return 0;
}
