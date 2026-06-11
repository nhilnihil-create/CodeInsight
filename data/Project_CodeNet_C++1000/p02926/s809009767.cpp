#include<iostream>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<tuple>
#include<cmath>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

struct vec {
  int64_t x, y;
  vec(): x(0), y(0) {}
  vec(int64_t x, int64_t y) : x(x), y(y) {}
  vec operator+(vec const& v) const { return vec(x + v.x, y + v.y); }
  vec operator-(vec const& v) const { return vec(x - v.x, y - v.y); }
  bool operator==(vec const& v) const {
    return x * v.y == y * v.x && x * v.x >= 0 && y * v.y >= 0;
  }

  bool operator<(vec const&v) const {
    if(*this == v) return false;
    if(y > 0 && v.y > 0) {
      if((x > 0 && v.x > 0) || (x < 0 && v.x < 0)) return y * v.x < x * v.y;
      if(x <= 0 && v.x >= 0) return false;
      return true;
    } else if (y < 0 && v.y < 0) {
      if((x < 0 && v.x < 0) || (x > 0 && v.x > 0)) return y * v.x < x * v.y;
      if(x >= 0 && v.x <= 0) return false;
      return true;
    } else if (y > 0 && v.y < 0) return true;
    if (y < 0 && v.y > 0) return false;
    if (y == 0 && x > 0 && (v.y != 0 || (v.y == 0 && v.x < 0))) return true;
    if (y == 0 && x < 0 && v.y < 0) return true;
    if (v.y == 0 && v.x < 0 && y > 0) return true;
    return false;
  }
  friend std::ostream& operator<<(std::ostream &os, const vec &v) {
    return os << "[" << v.x << "," << v.y << "]";
  }
};

int const MAXN = 100;
vec p[MAXN*2];
int N;

int main() {
  std::cout << std::setprecision(15) << std::fixed;
  std::cin >> N;
  int j = 0;
  for(int i = 0; i < N; ++i) {
    int x, y; std::cin >> x >> y;
    if(x == 0 && y == 0) continue;
    p[j++] = vec(x, y);
  }
  N = j;
  if(N < 1) fin(0.0);
  std::sort(p, p+N);
  for(int i = 0; i < N; ++i) p[i+N] = p[i];
  int64_t sum2 = 0, ans2 = 0;
  vec sum;
  j = 0;
  for(int i = 0; i < N; ++i) {
    while(j < i+N) { 
      vec nv = sum + p[j];
      int64_t n2 = nv.x*nv.x + nv.y*nv.y;
      if(n2 <= sum2) break;
      sum = nv; sum2 = n2;
      ans2 = std::max(ans2, sum2);
      ++j;
    }
    sum  = sum - p[i];
    sum2 = sum.x*sum.x + sum.y*sum.y;
    ans2 = std::max(ans2, sum2);
  }
  fin(std::sqrt((double)ans2));
  return 0;
}
