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

ll N,K;
vector<ll> A;
ll S=0;

bool isOK(ll g){
  vector<ll> mod1(N);
  vector<ll> mod2(N);
  rep(i,N){
    ll tmp=A.at(i)%g;
    mod1.at(i)=tmp;
    mod2.at(i)=g-tmp;
  }
  sort(all(mod1));
  sort(all(mod2));
  reverse(all(mod2));

  vector<ll> sum1(N+1,0);
  vector<ll> sum2(N+1,0);
  REP(i,1,N+1)  sum1.at(i)=sum1.at(i-1)+mod1.at(i-1);
  for(int i=N-1;i>=0;i--) sum2.at(i)=sum2.at(i+1)+mod2.at(i);

  ll cnt=1e18;
  rep(i,N+1)  chmin(cnt,max(sum1.at(i),sum2.at(i)));
  if(cnt<=K)  return true;
  else  return false;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin >> N >> K;
  A.resize(N);
  rep(i,N){
    cin >> A.at(i);
    S+=A.at(i);
  }

  ll ans=0;
  for(ll i=1;i*i<=S;i++){
    if(S%i!=0)  continue;
    if(isOK(i))  chmax(ans,i);
    if(isOK(S/i))  chmax(ans,S/i);
  }
  cout << ans << endl;

  return 0;
}