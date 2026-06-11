#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

uint64_t getZ() {
  uint64_t v = 0; int c;
  while((c = getchar_unlocked()) >= '0') v=v*10+c-'0';
  return v;
}

int const MAXN = 500;
int N, K, A[MAXN], tmp[MAXN], sum;

bool isOK(int v) {
  if(sum%v != 0) return false;
  int tsum = 0;
  for(int i = 0; i < N; ++i) tsum += (tmp[i] = A[i]%v);
  std::sort(tmp, tmp+N);
  int n = N - tsum/v;
  int x = 0;
  for(int i = 0; i < n; ++i) x += tmp[i];
  return x <= K;
}

int main() {
  N = getZ(); K = getZ(); sum = 0;
  for(int i = 0; i < N; ++i) sum += (A[i] = getZ());
  std::vector<int> divisors;
  for(int i = 1; i*i <= sum; ++i) {
    if(sum%i != 0) continue;
    divisors.push_back(i);
    if(i*i != sum) divisors.push_back(sum/i);
  }
  std::sort(divisors.begin(), divisors.end(), std::greater<int>());
  for(int i: divisors) if(isOK(i)) fin(i);
  return 0;
}
