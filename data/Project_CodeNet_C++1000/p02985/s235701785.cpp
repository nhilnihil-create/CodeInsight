#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define pb push_back
#define LIMIT 1000000007 //10^9+7
using ll = long long;
#define debug2(x,y) cout<<"("<<#x<<","<<#y<<") = ("<<(x)<<","<<(y)<<")\n"

namespace /* combination.cpp */{
  namespace /* modinv.cpp */{
    namespace /* extGCD.cpp */{
      long long extGCD(long long a, long long b, long long &x, long long &y) {
          if (b == 0) {
              x = 1;
              y = 0;
              return a;
          }
          long long d = extGCD(b, a%b, y, x);
          y -= a/b * x;
          return d;
      }
    }
    long long modinv(long long a, long long p){
      long long x, y;
      extGCD(a, p, x, y);
      return (x>0? x: x+p);
    }
  }
  long long l_fac(long long n){
    if(n<0) return -1;
    long long ans = 1;
    for(long long i=1; i<=n; i++){
      ans *= i;
      ans %= LIMIT;
    }
    return ans;
  }
  long long l_nPr(long long n, long long r){
    long long ans = 1;
    for(long long i=0; i<r; i++){
      ans *= (n-i);
      ans %= LIMIT;
    }
    return ans;
  }
  long long l_nCr(long long n, long long r){
    if(r > n/2) r = n-r;
    return l_nPr(n, r) * modinv(l_fac(r), LIMIT) % LIMIT;
  }
}

int N,K; //頂点 色
vvi G; //グラフ
vi seen; //訪問済み
ll ans;

void bfs(){
  queue<int> que;
  que.push(0);

  while(!que.empty()){
    int now = que.front();
    que.pop();
    seen[now] = true;
    if(now==0){
      //debug2(now+1, G[now].size());
      ans *= l_nPr(K-1, G[now].size());
      ans %= LIMIT;
    }else{
      //debug2(now+1, G[now].size()-1);
      ans *= l_nPr(K-2, G[now].size()-1);
      ans %= LIMIT;
    }

    for(int x: G[now]){
      if(seen[x])continue;
      que.push(x);
    }
  }
}

int main(){
  cin>>N>>K;
  G.resize(N);
  seen.resize(N, false);
  ans = 1;
  int a,b;
  for(int i=0; i<N-1; i++){
    cin>>a>>b;
    a--;b--;
    G[a].pb(b);
    G[b].pb(a);
  }

  bfs();

  cout<<ans*K%LIMIT<<endl;
}