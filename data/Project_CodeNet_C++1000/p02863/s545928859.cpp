#include <bits/stdc++.h>
using namespace std;
// #define LOCAL // 提出時はコメントアウト
#define DEBUG_

typedef long long ll;
const double EPS = 1e-9;
const ll INF = ((1LL<<62)-(1LL<<31));
typedef vector<ll> vecl;
typedef pair<ll, ll> pairl;
template<typename T, typename U> using mapv = map<T,vector<U>>;

#define ALL(v) v.begin(), v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define contains(S,x) find(ALL(S),x) != S.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> vector<vector<T>> genarr(ll n, ll m, T init) { return vector<vector<T>>(n,vector<T>(m,init)); }

///// DEBUG
#define DUMPOUT cerr
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
template<typename T>istream&operator>>(istream&is,vector<T>&vec){for(T&x:vec)is>>x;return is;}
template<typename T,typename U>ostream&operator<<(ostream&os,pair<T,U>&pair_var){os<<"("<<pair_var.first<<", "<<pair_var.second<<")";return os;}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&vec){os<<"{";for(int i=0;i<vec.size();i++){os<<vec[i]<<(i+1==vec.size()?"":", ");}
os<<"}";return os;}
template<typename T,typename U>ostream&operator<<(ostream&os,map<T,U>&map_var){os<<"{";repi(itr,map_var){os<<*itr;itr++;if(itr!=map_var.end())os<<", ";itr--;}
os<<"}";return os;}
template<typename T>ostream&operator<<(ostream&os,set<T>&set_var){os<<"{";repi(itr,set_var){os<<*itr;itr++;if(itr!=set_var.end())os<<", ";itr--;}
os<<"}";return os;}
void dump_func(){DUMPOUT<<endl;}
template<class Head,class...Tail>void dump_func(Head&&head,Tail&&...tail){DUMPOUT<<head;if(sizeof...(Tail)>0){DUMPOUT<<", ";}
dump_func(std::move(tail)...);}
#ifndef LOCAL
#undef DEBUG_
#endif
#ifdef DEBUG_
#define DEB
#define dump(...)                                                          \
DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
        << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
        << endl                                                            \
        << "    ",                                                         \
    dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

//////////

int main() {
    #ifdef LOCAL
    ifstream in("../../Atcoder/input.txt");
    cin.rdbuf(in.rdbuf());
    #endif

    ll N,T;
    cin>>N>>T;

    vecl A(N),B(N);
    rep(i,N) {
      cin>>A[i]>>B[i];
    }

    auto dpl = genarr(N+10,T+10,0LL); // [0,i)でt以下食うときのmax{B}
    auto dpr = genarr(N+10,T+10,0LL); // [i,N)でt以下食うときのmax{B}

    rep(i,N) {
      rep(j,T) {
        ll a = A[i];
        ll b = B[i];
        chmax(dpl[i+1][j],dpl[i][j]);
        if (j+a < T) {
          chmax(dpl[i+1][j+a],dpl[i][j]+b);
        }
      }
    }


    rep(i,N) {
      ll ii = N-1-i;
      rep(j,T) {
        ll a = A[ii];
        ll b = B[ii];
        chmax(dpr[ii][j],dpr[ii+1][j]);
        if (j+a < T) {
          chmax(dpr[ii][j+a],dpr[ii+1][j]+b);
        }
      }
    }


    ll ans = 0;
    rep(k,N) { //一番最後に食べる料理で全探索 
        rep(t,T) {
          chmax(ans,dpl[k][t] + dpr[k+1][T-1-t] + B[k]);
        }
    }

    dump(dpl);
    dump(dpr);

    cout << ans << endl;


    return 0;
}
