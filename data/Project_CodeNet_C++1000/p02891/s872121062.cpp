#include<bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<int >    vecint;
typedef vector<double >    vecd;
typedef vector<vector<int> >  vec2int;
typedef vector<vector<double> >  vec2d;
typedef vector<ll >     vecll;
typedef vector<string > vecstr;
typedef vector<bool > vecbool;
typedef vector<vector< bool > > vec2bool;
typedef vector<bool > vecbool;
////////////////////////////////////////////////
int main()
{
  string s; cin >> s;
  ll k; cin >> k;
  vector<pair<char, ll> > v;
  ll n = s.size();
  REP(i,n){
    char tmp = s[i];
    ll c = 1;
    while(s[i + 1] == tmp){
      i ++;
      c ++;
    }
    v.push_back(make_pair(tmp,c));
  }
  // REPvec(itr,v){
  //   cout << itr->first << " " << itr->second << endl;
  // }
  if(v.size() == 1){
    cout << (v[0].second*k)/2 << endl;
  }else if(v.front().first == v.back().first){
    ll ans = 0;
    for(int i = 1; i < v.size() - 1; i ++){
      ans += v[i].second/2;
    }
    ans *= k;
    ans += (k - 1)*((v.front().second + v.back().second)/2);
    ans += v.front().second/2;
    ans += v.back().second/2;
    cout << ans << endl;
  }else{
    ll ans = 0;
    REPvec(itr, v){
      ans += itr->second/2;
    }
    cout << k*ans << endl;
  }
}