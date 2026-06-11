#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

double L(int x,int y){
  return sqrt(x*x+y*y);
}

int main() {
  int N;
  cin>>N;
  vector<int> X(N),Y(N);
  rep(i,N) cin>>X[i]>>Y[i];
  vector<int> v(N);
  rep(i,N) v[i] = i;
  double ans = 0;
  do{
    rep(i,N-1){
      ans += L(X[v[i+1]]-X[v[i]],Y[v[i+1]]-Y[v[i]]);
    }
  }while(next_permutation(v.begin(),v.end()));
  ll p = 1;
  rep(i,N) p *= i+1;
  ans = ans / p;
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
}