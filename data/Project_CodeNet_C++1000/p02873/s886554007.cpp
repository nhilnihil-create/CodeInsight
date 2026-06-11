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
  string s;
  cin >> s;
  s.push_back(0);

  vector<int> l;
  vector<int> r;
  int cnt = 0;
  REP(i,s.size()-1){
    cnt++;
    if(s[i] != s[i+1]){
      if(s[i] == '<') l.push_back(cnt);
      else r.push_back(cnt);
      cnt = 0;
    }
  }
  //
  // for(auto x: l) cout << x << " ";
  // cout<< endl;
  // for(auto x: r) cout << x << " ";
  // cout << endl;

  if(l.empty()){
    ll a = r[0];
    cout << (a+1)*a/2;
    return 0;
  }

  if(r.empty()){
    ll a = l[0];
    cout << (ll)(a+1)*a/2;
    return 0;
  }

  ll sum = 0;
  if(s[0] == '>'){
    int a = r[0];
    sum += (ll)a*(a+1)/2;
    r.erase(r.begin());
  }


  if(r.size() < l.size()) {
    r.push_back(0);
  }
  //
  // for(auto x: l) cout << x << " ";
  // cout<< endl;
  // for(auto x: r) cout << x << " ";
  // cout << endl;

  REP(i,l.size()){
    int a = l[i];
    int b = r[i];
    if(b > a) swap(a,b);
    b--;
    sum += (ll)a*(a+1)/2 + b*(b+1)/2;
  }

  cout << sum << endl;

  return 0;
}
