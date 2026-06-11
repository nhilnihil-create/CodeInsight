#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, a, n) for(int i=a; i<n; i++)
#define ll long long
#define all(x) begin(x), end(x)
#define toInt(x) (x - '0')
#define pll pair<ll, ll>
#define pli pair<ll, int>

const long long INF = 1LL<<60;
const int inf = 1 << 30;
const int mod = 1e9+7;


template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


vector<pair<ll, int>> factrized(ll num){
  vector<pair<ll, int>>  res;
 
  for(ll i = 2; i * i <= num; i++){
    if(num % i)continue;
    res.emplace_back(i, 0);
    while(num % i == 0){
      num /= i;
      res.back().second++;
    }
  }
  if(num != 1) res.emplace_back(num, 1);
  return res;
}

int main(){
  long long s;
  cin >> s;
  // 0 0 1 1e9
  int x2 = 1e9;
  int y2 = 1;

  int x3 = (x2 - (s % x2)) % x2;
  int y3 = s / x2 + 1;
  if (s % x2 == 0){
    x3 = 0;
    y3 = s / x2;
  }
  printf("%d %d %d %d %d %d\n",0, 0, x2, y2, x3, y3);
}
