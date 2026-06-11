#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;


void solve(long long N, long long Q, std::vector<long long> a, std::vector<long long> b, std::vector<long long> p, std::vector<long long> x){
  map<ll,vector<ll>> m;
  vector<ll> v(N+1, 0);
  for(int i=0; i<N; i++) {
    m[i+1] = vector<ll>();
  }
  for(int i=0; i<N; i++) {
    m[a[i]].push_back(b[i]);
    m[b[i]].push_back(a[i]);
  }
  for(int i=0; i<Q; i++) {
    v[p[i]] += x[i];
  }
  queue<int> q;
  q.push(1);
  vector<ll> ch(N+1, 0);
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    ch[x] = 1;
    for(auto chi : m[x]) {
      if(ch[chi] == 0) {
	v[chi] += v[x];
	q.push(chi);
      }
    }
  }
  for(int i=0; i<N; i++) {
    if(i+1 == N) std::cout << v[i+1] << std::endl;
    else std::cout << v[i+1] << ' ';
  }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> a(N-1);
    std::vector<long long> b(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    std::vector<long long> p(Q);
    std::vector<long long> x(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&p[i]);
        scanf("%lld",&x[i]);
    }
    solve(N, Q, std::move(a), std::move(b), std::move(p), std::move(x));
    return 0;
}
