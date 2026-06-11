#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
using P = pair<ll,ll>;

template <typename T>
class SegTree{
  using F = function<T(T,T)>;
  int n; T uni; F f;
  vector<T> dat;
  T query_sub(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) return uni;
    if(a <= l && r <= b) return dat[k];
    T vl = query_sub(a, b, k*2+1, l, (l+r)/2);
    T vr = query_sub(a, b, k*2+2, (l+r)/2, r);
    return f(vl,vr);
  }
public:
  SegTree(int _n, F f, T uni) : f(f), uni(uni) {
    n = 1;
    while(n < _n) n *= 2;
    dat = vector<T>(2*n-1,uni);
  }
  void update(int k, T a) {
    k += n-1;
    dat[k] = a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] = f(dat[2*k+1], dat[2*k+2]);
    }
  }
  T query(int a, int b) {
    return query_sub(a, b, 0, 0, n);
  } // [a,b)
};

int main(){
  int n;
  cin >> n;
  ll a[n], b[n];
  SegTree<P> st(n,[](P a, P b){return max(a,b);},P(-1,-1));
  bool can = true;
  rep(i,n) cin >> a[i];
  rep(i,n) {
    cin >> b[i];
    if(a[i] > b[i]) can = false;
    st.update(i,P(b[i],i));
  }
  if(!can) {
    cout << -1 << endl;
    return 0;
  }
  ll d = 0;
  vector<bool> fix(n,false);
  while(true) {
    P p = st.query(0,n);
    if(p.first == -1) break;
    int l = (p.second-1+n) % n, r = (p.second+1) % n;
    ll s = b[l] + b[r];
    ll c = min(b[p.second]/s,(b[p.second]-a[p.second])/s);
    if(c == 0) {
      fix[p.second] = true; st.update(p.second,P(-1,p.second));
    } else {
      b[p.second] -= s*c;
      st.update(p.second,P(b[p.second],p.second));
      d += c;
    } 
  }
  rep(i,n) {
    if(a[i] != b[i]) can = false;
  }
  cout << (can? d : -1) << endl;
  return 0;
}