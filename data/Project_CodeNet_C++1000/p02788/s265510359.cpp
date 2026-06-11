#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define PI 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define vi2 vector<vector<int>>
#define eb emplace_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
using P = pair<ll,ll>;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};
#define INT(name) int name;cin >> name;
#define VEC(type,name,n) vector<type> name(n);REP(i,n) cin >> name[i];

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  ll N,D,A;
  cin >> N >> D >> A;
  vector<P> B(N);
  REP(i,N){
    cin >> B[i].first >> B[i].second;
  }
  sort(ALL(B));

  vector<ll> vec(N);
  ll right=0;
  REP(left,N){
    while(B[right].first-B[left].first<=2*D&&right<N){
      right++;
    }
    if(right==left){
      right++;
    }
    vec[left]=right;
  }

  vector<ll> imos(N+1,0);
  ll cnt = 0;
  REP(i,N){
    B[i].se-=A*imos[i];
    if(B[i].se<0){
      imos[i+1]+=imos[i];
      continue;
    }
    ll attack;
    if(B[i].se%A==0){
      attack=B[i].se/A;
    }else{
      attack=B[i].se/A+1;
    }
    imos[i]+=attack;
    imos[vec[i]]-=attack;
    imos[i+1]+=imos[i];
    cnt+=attack;
  }

  cout << cnt << endl;
}