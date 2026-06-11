#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)
#define MOD 1000000007

//debug
#define debug(arr) cerr<<#arr<<"(l"<<__LINE__<<") : ";for(auto x:arr)cerr<<x<<" ";cerr<<endl;

ll N, M, Q;
vll a, b, c, d;

ll calc_score(vll& A){
  ll res = 0;
  rep(q, Q){
    if(A[b[q]-1] - A[a[q]-1] == c[q])
      res += d[q];
  }
  return res;
}

ll max_score(vll A, ll n){
  A.push_back(n);
  if(A.size() == N) return calc_score(A);
  else{
    ll res = -1, tmp;
    repi(i, n, M+1){
      tmp = max_score(A, i);
      if(tmp > res) res = tmp;
    }
    return res;
  }
}

int main(){
  ll a_, b_, c_, d_;
  cin >> N >> M >> Q;
  rep(i, Q){
    cin >> a_ >> b_ >> c_ >> d_;
    a.push_back(a_);
    b.push_back(b_);
    c.push_back(c_);
    d.push_back(d_);
  }
  vll A;
  cout << max_score(A, 1) << endl;
  return 0;
}

