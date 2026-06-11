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
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
  int m;
  cin >> m;
  vl d(m),c(m);
  rep(i,m) cin >> d.at(i) >> c.at(i);
  long num[10] = {-1,10,5,4,3,2,2,2,2,2};
  long to[10] = {-1,1,1,3,3,1,3,5,7,9};
  long ans = 0;
  vl s;
  rep(i,m){
    long x = d.at(i);
    long y = c.at(i);
    if(x == 0){
      ans += y;
    }else{
      while(y){
        long r = y % num[x];
        ans += r-1;
        s.push_back(r*x);
        ans += (y / num[x])*num[x];
        y /= num[x];
        x = to[x];
      }
    }
  }
  long now = s.at(0);
  for(int i=1;i<s.size();i++){
    now += s.at(i);
    ans++;
    if(now >= 10){
      now = now/10 + now%10;
      ans++;
    }
  }
  cout << ans << endl;
}