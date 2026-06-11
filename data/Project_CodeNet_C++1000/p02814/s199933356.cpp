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

int calc(ll a){
  int ans=0;
  while(a%2==0){
    a/=2;
    ans++;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i,N){
    cin >> A.at(i);
    A.at(i)/=2;
  }

  int cnt=calc(A.at(0));
  rep(i,N){
    if(cnt != calc(A.at(i))){
      cout << 0 << endl;
      return 0;
    }
  }

  ll x=1;
  rep(i,N)  x=lcm(x,A.at(i));
  cout << M/x - M/(2*x) << endl;

  return 0;
}