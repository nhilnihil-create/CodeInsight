#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }
template<typename T>
void put(std::string& buf, T const& ans) { buf += std::to_string(ans) + "\n"; }

int const MAXN = 3e5;
int const MAXA = 6.4e5;
int N, f[MAXN];

int main() {
  std::cin >> N;
  std::map<int,int> m;
  for(int i = 0; i < N; ++i) { int A; std::cin >> A; ++m[A]; }
  int n = 0;
  std::map<int,int> d;
  for(auto s: m) ++d[s.second];
  int sum = 0;
  for(int x = 0; x < N; ++x) {
    if(d.count(x) > 0) sum += x*d[x];
    f[x] = sum/(x+1);
  }
  sum = d[N];
  for(int x = N-1; x >= 0; --x) {
    f[x] += sum;
    if(d.count(x) > 0) sum += d[x];
  }
  
  std::string ans_s;
  ans_s.reserve(MAXA);
  int ans = N;
  for(int k = 1; k <= N; ++k) {
    ans = std::min(ans, N/k);
    while(ans > 0 && k > f[ans-1]) --ans;
    put(ans_s, ans);
  }
  fin(ans_s);
  return 0;
}
