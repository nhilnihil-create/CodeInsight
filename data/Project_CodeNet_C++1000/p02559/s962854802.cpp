#include<iostream>
#include<vector>

template<class T>
struct fenwick_tree{
  int n;
  std::vector<T> data;
  fenwick_tree(){}
  fenwick_tree(int _n):n(_n){
    data.resize(n+1);
  }
  template<class U>
  fenwick_tree(std::vector<U>const& a):n(a.size()){
    data.resize(n+1);
    for(int i=1;i<=n;++i){
      data[i] += a[i-1];
      if(i+(i&-i)<=n)data[i+(i&-i)] += data[i];
    }
  }
  T prefix_sum(int x){
    T res{0};
    for(int i=x;i>0;i-=i&-i)res+=data[i];
    return res;
  }
  T fold(int l,int r){
    return prefix_sum(r)-prefix_sum(l);
  }
  void add(int x,T v){
    for(int i=x+1;i<=n;i+=i&-i)data[i]+=v;
  }
  int lower_bound(T w){
    int k = 0;
    int sz=1;while(sz<n)sz<<=1;
    for(int i=sz;i>0;i>>=1){
      if(k+i<=n&&data[k+i]<w){
        w -= data[k+i];
        k += i;
      }
    }
    return k;
  }
};

int main(){
  using namespace std;
  using ll = int64_t;
  cin.tie(0);
  ios::sync_with_stdio(false);
  constexpr char newl = '\n';

  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  for(auto& ai:a)cin>>ai;

  fenwick_tree<ll> fen(a);
  while(q--){
    int t;cin>>t;
    if(t==0){
      int p,x;cin>>p>>x;
      fen.add(p,x);
    }
    if(t==1){
      int l,r;cin>>l>>r;
      cout<<fen.fold(l,r)<<newl;
    }
  }
}