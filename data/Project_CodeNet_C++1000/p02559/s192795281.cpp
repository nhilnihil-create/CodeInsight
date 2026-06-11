#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll=long long;
using Graph=vector<vector<int>>;
using pp=pair<ll,pair<ll,ll>>;
#define MAX 1000000
#define MOD 998244353
#define INF 1000000000000000000

int main(){
  int N,Q;
  cin>>N>>Q;
  fenwick_tree<ll> tree(N);
  for(int i=0;i<N;i++){
    ll a;
    cin>>a;
    tree.add(i,a);
  }
  for(int i=0;i<Q;i++){
    ll q,l,r;
    cin>>q>>l>>r;
    if(q==0){
      tree.add(l,r);
    }else{
      cout<<tree.sum(l,r)<<endl;
    }
  }
}
