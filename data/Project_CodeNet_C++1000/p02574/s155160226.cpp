#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;

struct sieveOfEratosthenes {
  vi divisor,primes;
  sieveOfEratosthenes(int N) :
    divisor(N+1,0) 
  {
    iota(rng(divisor),0);
    srep(i,2,N+1) {
      if(divisor[i]==i) {
        primes.emplace_back(i);
        for(int j=i;j<=N;j+=i) {
          divisor[j]=i;
        }
      }
    }
  }
  map<ll,int> primefact(ll x) {
    map<ll,int> res;
    if(x < sz(divisor)) {
      while(x>1) {
        res[divisor[x]]++;
        x /= divisor[x];
      }
    } else {
      for(int p:primes) {
        while(x%p==0) {
          x /=p;
          res[p]++;
        }
        if(x==1) break;
      }
      if(x>1) res[x]++;
    }
    return res;
  }
};

sieveOfEratosthenes s(1000000);
  
int main() {
  int N;
  cin >> N;
  vi A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vi cnt(1000010,0);
  int g = A[0];
  int ma=0;
  rep(i,N) {
    g = __gcd(A[i],g);
    for(auto p:s.primefact(A[i])) {
      cnt[p.first]++;
      chmax(ma,cnt[p.first]);
    }
  }
  if(ma<=1) {
    cout << "pairwise coprime" << endl;
    return 0;
  }
  if(g==1) {
    cout << "setwise coprime" << endl;
    return 0;
  }
  cout << "not coprime" << endl;
  return 0;
}