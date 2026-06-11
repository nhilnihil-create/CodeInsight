#include<iostream>
#include<cstdlib>
#include<cstdio>
template<int BUFSIZE>
struct ans_buf {
  char buf[BUFSIZE];
  int i;
  ans_buf(): i(0) {}
  void putZ(unsigned int v, char delim='\n') {
    unsigned int k = 1;
    while(k <= v/10) k*=10;
    for(; k>0; v%=k, k/=10) buf[i++] = (v/k)+'0';
    buf[i++] = delim;
  }
  void out() { std::fwrite(buf, 1, i, stdout); }
};
char inbuf[1<<18];
unsigned int getZ() {
  unsigned int v = 0; int c;
  while((c = getchar_unlocked()) >= '0') v=v*10+c-'0';
  return v;
}

int const MAXN = 3e5;
int const MAXA = 6.4e5;
int N, m[MAXN], d[MAXN+1];

int main() {
  std::setbuf(stdin, inbuf);
  N = getZ();
 // std::fill_n(m, N, 0);
  for(int i = 0; i < N; ++i) ++m[getZ()-1];
  //std::fill_n(d, N+1, 0);
  for(int i = 0; i < N; ++i) ++d[m[i]];
 
  ans_buf<MAXA> buf;
  int sum_D = 0, sum_iD = N, k = 1;
  for(int ans = N; ans >= 1; --ans) {
    sum_D += d[ans];
    sum_iD -= d[ans]*ans;
    int next_k = sum_iD/ans + sum_D + 1;
    for(int i = k; i < next_k; ++i) buf.putZ(ans);
    k = next_k;
  }
  while(k <= N) { buf.putZ(0); ++k; }
  buf.out();
  return 0;
}
