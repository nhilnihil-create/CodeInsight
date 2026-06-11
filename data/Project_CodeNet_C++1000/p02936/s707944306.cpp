#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

vector<int> to[200005];
vector<int> ans;

void dfs(int v, int p=-1) {
  for(int u : to[v]) {
    if(u == p) continue;
    ans[u] += ans[v];
    dfs(u,v);
  }
}

int main() {
  int n,q; cin >> n >> q;

  rep(i,n-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    
    to[a].push_back(b);
    to[b].push_back(a);
  }

  ans.resize(n);
  rep(i,q) {
    int p,x;

    cin >> p >> x;
    --p;
    ans[p] += x;
  }
  dfs(0);
  
  rep(i,n) {
    cout << ans[i] << endl;
  }
}
