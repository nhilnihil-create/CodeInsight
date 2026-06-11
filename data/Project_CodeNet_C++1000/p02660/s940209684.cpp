#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
typedef int64_t ll;

map<int64_t,int> prime_factor(int64_t n) {
  map<int64_t,int> ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}


int main() {
    ll N, ans = 0;
    cin >> N;
    map<ll, int> p;
    p = prime_factor(N);
    for (auto x: p){
        int a, b, c = 1;
        a = x.first;
        b = x.second;
        while(c <= b){
            b -= c;
            ans++;
            c++;
        }
    }
    cout << ans << endl;
}