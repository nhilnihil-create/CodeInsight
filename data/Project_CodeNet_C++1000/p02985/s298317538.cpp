#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,k;
  cin >> n >> k;
  vector<vector<int>> v(n);
  rep(i,n-1){
    int a,b;cin >> a >> b;
    a--,b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  vector<int> d(n,-1);
  d[0] = 0;
  queue<int> que;
  que.push(0);
  ll res = k;
  while(!que.empty()){
    int ov = que.front();que.pop();
    int size = v[ov].size();
    if(ov == 0)for(ll i = k-1;i >= k-size;i--)(res *= i)%= MOD;
    else for(ll i = k-2;i > k-1-size;i--)(res *= i)%= MOD;
    for(int nv : v[ov]){
      if(d[nv] != -1)continue;
      d[nv] = d[ov]+1;
      que.push(nv);
    }
  }
  cout << res << endl;



  return 0;
}