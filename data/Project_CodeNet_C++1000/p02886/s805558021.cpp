#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  REP(i,n) cin >> d[i];
  ll sum = 0;
  REP(i,n-1){
    for(int j = i + 1; j < n; j++){
      sum += d[i]*d[j];
    }
  }

  cout << sum << endl;
  return 0;

}

