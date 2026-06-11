#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <climits>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <random>
using namespace std;

using Pair = pair<int, int>;
using lint = long long;

#define rep(i, n) for (int i = 0; i < (n); i++)

// const int mod = 1e9 + 7;
// const int mod = 998244353;

template <typename T> vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
#include <utility>
#include <vector>
struct UnionFind {
  std::vector<int> par, siz;
  void init(int n) {
    par.resize(n);
    for (int i = 0; i < n; i++)
      par[i] = i;
    siz.resize(n, 1);
  }
  UnionFind(int n) {
    init(n);
  }
  int root(int n) {
    if (par[n] == n)
      return n;
    else
      return par[n] = root(par[n]);
  }
  bool issame(int x, int y) {
    return (root(x) == root(y));
  }
  bool marge(int a, int b) {
    if (issame(a, b))
      return false;
    else {
      a = root(a), b = root(b);
      if (siz[a] < siz[b]) std::swap(a, b);
      siz[b] += siz[a];
      par[a] = par[b];
      return true;
    }
  }
  int size(int n) {
    return siz[root(n)];
  }
};
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
lint solver1(int n,int k,vector<int> p,vector<int> c){
  UnionFind uf(n);
  rep(i, n) {
    uf.marge(i, p[i] - 1);
  }
  lint ret = -LLONG_MAX;
  rep(i, n) {
    lint mx = -LLONG_MAX;
    lint po = 0, sum = 0;
    rep(j, n) {
      if (uf.issame(i, j)) sum += c[j];
    }
    if (sum <= 0) {
      int now = i;
      rep(j, min(k, uf.size(i))) {
        now = p[now] - 1;
        po += c[now];
        chmax(mx, po);
      }
    } else {
      int cl=k/uf.size(i),am=k%uf.size(i);
      cl--;
      am+=uf.size(i);
      po = sum * (cl);
      int now = i;
      if (cl > 0) chmax(mx, po);
      rep(j, am) {
        now = p[now] - 1;
        po += c[now];
        chmax(mx, po);
      }
    }
    chmax(ret, mx);
  }
  if (ret == 0) {
    ret = c[0];
    rep(i, n) {
      chmax(ret, (lint)c[i]);
    }
  }
  return  ret;
}
lint solver2(int n,int k,vector<int> p,vector<int> c){
  lint ret=-LLONG_MAX;
  rep(i,n){
    lint cnt=0;
    int now=i;
    rep(j,k){
      now=p[now]-1;
      cnt+=c[now];
      chmax(ret,cnt);
    }
  }
  return ret;
}
void input(int &n,int &k,vector<int> &p,vector<int> &c){
  cin>>n>>k;
  p.resize(n); c.resize(n);
  rep(i,n)cin>>p[i];
  rep(i,n)cin>>c[i];
}
void ram(int &n, int &k, vector<int> &p, vector<int> &c) {
  std::random_device seed_gen;
  mt19937_64 engine(seed_gen());
  n=engine()%5;
  k=engine()%10;
  p.resize(n,-1);
  c.resize(n);
  fill(p.begin(),p.end(),-1);
  rep(i, n) {
    int idx=engine()%(n-i);
    int cnt=0;
    rep(j,n){
      if(p[j]==-1){
        if(cnt==idx){
          p[j]=i+1;
          break;
        }
        cnt++;
      }
    }
  }
  rep(i, n){
    c[i]=engine()%20*pow(-1,engine()%2);
  }
}
int main(){
  int n,k;
  vector<int> p, c;
  int cnt=0;
  /*while(1){
    cout<<cnt<<endl;
    cnt++;
    ram(n,k,p,c);
    if(solver1(n,k,p,c)!=solver2(n,k,p,c)){
      cout<<n<<" "<<k<<endl;
      rep(i,n){
        cout<<p[i]<<" ";
      }
      cout<<endl;
      rep(i, n) {
        cout << c[i] << " ";
      }
      cout << endl;
      cout<<solver1(n,k,p,c)<<" "<<solver2(n,k,p,c)<<endl;
      break;
    }
  }*/
  input(n,k,p,c);
  cout<<solver1(n,k,p,c)<<endl;
}
