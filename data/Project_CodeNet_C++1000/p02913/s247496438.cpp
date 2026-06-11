#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};

class RollingHash{
  public:
  const ull mod = (1ull << 61)-1;
  const ull MASK31 = (1ull << 31)-1;
  vector<ull> pows;
  vector<ull> hash;
  const ull base = 1162261467;
  string s;
  RollingHash(string t) : pows(t.size()+1,1),hash(t.size()+1,0),s(t){
    REP(i,s.size())pows[i+1] = calcmod(mul(pows[i],base));
    REP(i,s.size())hash[i+1] = calcmod(mul(hash[i],base)+s[i]);
  }
  ull gethash(ll l,ll r){
    return calcmod(hash[r]+mod*4-mul(hash[l],pows[r-l]));
  }
  ull mul(ull n,ull r){
    ull nu = n >> 31,nd = n & MASK31;
    ull ru = r >> 31,rd = r & MASK31;
    return ((nu*ru) << 1) + nd * rd + (((nu*rd+nd*ru) >> 31) << 1) + (((nu*rd + nd*ru)&MASK31) << 31);
  }
  ull calcmod(ull n){
    ull u = n >> 61,d = n & mod;
    return (u+d >= mod) ? u+d-mod : u+d;
  }
};

int main(){

  int n;
  string s;
  cin >> n >> s;
  int res = 0;
  RollingHash rh(s);
  vector<tuple<ull,int,int>> v;
  for(ll i = n/2;i > 0;i--){
    for(ll j = 0;i+j <= n;j++){
      v.push_back(make_tuple(rh.gethash(j,j+i),i,j));
    }
  }
  sort(ALL(v));
  v.push_back(make_tuple(rh.mod,0,0));
  int old = 0;
  REP(i,v.size()-1){
    if(get<0>(v[i]) != get<0>(v[i+1])){
      if((get<2>(v[old]) < get<1>(v[i])+get<2>(v[i])) && (get<2>(v[old]) >= get<2>(v[i]))){
        old = i+1;
        continue;
      }
      if((get<2>(v[i]) < get<1>(v[old])+get<2>(v[old])) && (get<2>(v[i]) >= get<2>(v[old]))){
        old = i+1;
        continue;
      }
      res = max(res,get<1>(v[i]));
      old = i+1;
    }
  }
  cout << res << endl;



  

  return 0;
}
