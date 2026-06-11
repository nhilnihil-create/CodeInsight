#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  int n;
  std::cin >> n;
  vt<ll> a(n);
  rep(i,n)
    std::cin >> a[i];

  int p = 1, q = n-1;
  ll length = a[0];
  while(p <= q) {
    if(length >= 0) {
      length -= a[q];
      --q;
    }
    else {
      length += a[p];
      ++p;
    }
  }

  std::cout << (int)abs(length) << '\n';
  return 0;
}
