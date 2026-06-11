#include <bits/stdc++.h>

template <typename T>
std::vector<std::complex<T>> convex_hull(std::vector<std::complex<T>> points) {
  std::sort(points.begin(), points.end(), [](const std::complex<T>& a, const std::complex<T>& b) {
    return (std::real(a) < std::real(b)) || ((std::real(a) == std::real(b)) && std::imag(a) < std::imag(b));
  });
  points.erase(std::unique(points.begin(), points.end()), points.end());

  int n = points.size(), k = 0;
  if (n < 3) return points;
  else {
    auto cross = [](const std::complex<T>& a, const std::complex<T>& b) {
      return std::real(a) * std::imag(b) - std::imag(a) * std::real(b);
    };

    std::vector<std::complex<T>> ret(n << 1);
    for (int i = 0; i < n; ret[k++] = points[i++]) {
      while (k >= 2 && cross(ret[k - 1] - ret[k - 2], points[i] - ret[k - 1]) <= 0) --k;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ret[k++] = points[i--]) {
      while (k >= t && cross(ret[k - 1] - ret[k - 2], points[i] - ret[k - 1]) <= 0) --k;
    }
    ret.resize(k - 1);
    return ret;
  }
}

using namespace std;

long long distance(const complex<long long>& a, const complex<long long>& b){
  complex<long long> c = a - b;
  return abs(real(c)) + abs(imag(c));
}

signed main(){
  int N;
  cin >> N;
  
  vector<complex<long long>> ps(N);
  for(int i = 0; i < N; i++){
    long long x, y;
    cin >> x >> y;
    ps[i] = complex<long long>(x, y);
  }
  
  vector ch = convex_hull(ps);
  
  int k = ch.size();
  
  long long max_dist = 0;
  for(int i = 0, r = 0; i < k; i++){
    while((r + 1) % k != i && distance(ch[i], ch[(r + 1) % k]) >= distance(ch[i], ch[r % k])) ++r;
    max_dist = max(distance(ch[i], ch[r % k]), max_dist);
    if(i == r) ++r;
  }
  
  cout << max_dist << endl;
  
  return 0;
}