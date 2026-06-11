#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


ll lcm(ll a, ll b){
  return a / __gcd(a,b) *b;
}

int main(){
  ll a, b;
  cin >> a >> b;
  cout << lcm(a,b) << endl;

  return 0;
}