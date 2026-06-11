#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define uniq(x) ((x).erase(unique(all(x)),(x).end()))
#define sz(x) ((int)(x).size())

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

#ifdef LOCAL//compile with -DLOCAL
#define debug(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl
#define debug_vec(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = ";\
  rep(i,sz(x)){cerr<<x[i]<<" ";}cerr<<endl
#define debug_mat(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<endl;\
  rep(i,sz(x)){rep(j,sz(x[i])){cerr<<x[i][j]<<" ";}cerr<<endl;}cerr<<endl
#else
#define debug(x) void(0)
#define debug_vec(x) void(0)
#define debug_mat(x) void(0)
#endif

template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  cin >> N;
  vector<int> pos(N);
  rep(i,N){
    int p;
    cin >> p;
    p--;
    pos.at(p)=i+1;
  }

  ll ans=0;
  set<int> S;
  S.insert(0);
  S.insert(N+1);
  for(int i=N-1;i>=0;i--){
    int x=pos.at(i);
    set<int>::iterator it_l = S.lower_bound(x);
    set<int>::iterator it_r = S.lower_bound(x);
    it_l--;
    if(*it_l != 0){
      set<int>::iterator tmp = it_l;
      tmp--;
      ans += ll(i+1) * ll((*it_l) - (*tmp)) * ll((*it_r) - x);
    }
    if(*it_r != N+1){
      set<int>::iterator tmp = it_r;
      tmp++;
      ans += ll(i+1) * ll((*tmp) - (*it_r)) * ll(x - (*it_l));
    }
    S.insert(x);
  }
  cout << ans << endl;

  return 0;
}