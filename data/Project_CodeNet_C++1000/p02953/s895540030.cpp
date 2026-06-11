#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;

  vi h(n);
  rep(i,n) cin >> h.at(i);

  int pre = -999;
  rep(i,n){
    if (pre <= h.at(i) - 1) pre = h.at(i) - 1;
    else if (pre <= h.at(i)) pre = h.at(i);
    else {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}
