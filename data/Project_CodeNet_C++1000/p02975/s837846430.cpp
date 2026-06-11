#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
using vc = vector<char>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
  int n;
  cin >> n;
  vl a(n);
  rep(i,n) cin >> a.at(i);
  sort(all(a));
  if(a.at(n-1) == 0){
    YES;
    return 0;
  }
  if(n % 3 != 0){
    NO;
    return 0;
  }
  int m = n/3;
  long comp1 = a.at(0);
  rep(i,m){
    if(a.at(i) != comp1){
      NO;
      return 0;
    }
  }
  long comp2 = a.at(m);
  REP(i,m,2*m){
    if(a.at(i) != comp2){
      NO;
      return 0;
    }
  }
  long comp3 = a.at(2*m);
  REP(i,2*m,3*m){
    if(a.at(i) != comp3){
      NO;
      return 0;
    }
  }
  if(comp1 ^ comp2 ^ comp3) NO;
  else YES;
}