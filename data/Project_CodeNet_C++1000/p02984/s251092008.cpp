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
  long sum = 0;
  rep(i,n){
    cin >> a.at(i);
    sum += a.at(i);
  }
  long sub = 0;
  RNG(i,1,n,2){
    sub += a.at(i);
  }
  vl d(n);
  d.at(0) = sum - sub*2;
  REP(i,1,n){
    d.at(i) = 2*a.at(i-1) - d.at(i-1);
  }
  rep(i,n) cout << d.at(i) << " ";
  cout << endl;
}