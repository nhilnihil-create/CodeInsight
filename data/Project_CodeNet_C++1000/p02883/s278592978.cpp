#include<bits/stdc++.h>
using namespace std;

template<typename T, typename F> const T bsearch(T l, T h, const T& err, const F& f) {
  while(h - l > err) {
    auto m = (l + h) / 2;
    if(f(m)) h = m;
    else     l = m;
  }
  return h;
}

using LL = long long;

int main() {
  LL N, K;
  cin >> N >> K;
  vector<LL> A(N), F(N);
  for(auto* v: {&A, &F}) for(auto& i: *v) cin >> i;

  sort(begin(A), end(A));
  sort(begin(F), end(F));
  reverse(begin(F), end(F));

  LL L=-1, H=1e18+1, R=1e6+1, E=1;
  cout << bsearch(L,H,E,[&](auto x){
    LL n = 0;
    for(auto i=0; i<N; ++i) n += bsearch(L,R,E,[&a=A[i],&f=F[i],&x](auto k){return (a-k)*f<=x;});
    return n <= K;
  }) << endl;
}
