#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int N;
std::string S;

int64_t const B1 = 1e8+7;
int64_t const B2 = 1e9+7;

// Rolling Hash
bool isOK(int l) {
  int64_t r1 = 0, r2 = 0;
  std::map<int64_t, int> m1, m2;
  int64_t B1l = 1, B2l = 1;
  for(int i = 0; i < l; ++i) { B1l *= B1; B2l *= B2; }
  int i, j;
  for(i = 0; i < l; ++i) {
    r1 = r1*B1 + S[i];
    r2 = r2*B2 + S[i];
  }
  m1[r1] = m2[r2] = j = 0;
  for(; i < N; ++i) {
    r1 = r1*B1 + S[i] - S[j]*B1l;
    r2 = r2*B2 + S[i] - S[j]*B2l;
    ++j;
    if(m1.count(r1) && m1[r1] <= j-l && 
       m2.count(r2) && m2[r2] <= j-l) return true;
    if(m1.count(r1) < 1) m1[r1] = j;
    if(m2.count(r2) < 1) m2[r2] = j;
  }
  return false;
}

int main() {
  std::cin >> N >> S;
  int ok = 0, ng = N/2+1;
  while(ng - ok > 1) {
    int mid = (ok+ng)/2;
    if(isOK(mid)) ok = mid; else ng = mid;
  }
  fin(ok);
  return 0;
}
