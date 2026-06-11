#include <bits/stdc++.h>
using namespace std;


template<typename T>
struct Pt {
  T x, y;
  Pt() : x(T()), y(T()) {
  }
  Pt(T x_, T y_) : x(x_), y(y_) {
  }
  bool operator<(const Pt& other) const {
    if(x == other.x) {
      return y < other.y;
    }
    return x < other.x;
  }
  bool operator==(const Pt& other) const {
    return x == other.x && y == other.y;
  }
  bool operator<=(const Pt& other) const {
    return *this < other || *this == other;
  }
  bool operator>(const Pt& other) const {
    return !(*this <= other);
  }
  bool operator>=(const Pt& other) const {
    return !(*this < other);
  }
  Pt operator-(const Pt& other) const {
    return {x - other.x, y - other.y};
  }
  Pt operator+(const Pt& other) const {
    return {x + other.x, y + other.y};
  }
};

template<typename T>
Pt<T> operator+(Pt<T> a, Pt<T> b) {
  return {a.x + b.x, a.y + b.y};
}

template<typename T> typename common_type<long long, T>::type
cross_z(Pt<T> const& v1, Pt<T> const& v2) {
  using R = typename common_type<long long, T>::type;
  return (R) v1.x * v2.y - (R) v1.y * v2.x;
}

template<typename T> typename common_type<long long, T>::type
dot(Pt<T> const& v1, Pt<T> const& v2) {
  using R = typename common_type<long long, T>::type;
  return (R) v1.x * v2.x + (R) v1.y + v2.y;
}

template<typename T>
auto spin(Pt<T> const& a, Pt<T> const& b, Pt<T> const& c) {
  // spin of a -> b -> c
  // return > 0 : counterclockwise
  // return = 0 : collinear
  // return < 0 : clockwise
  return cross_z(b - a, c - a);
}

template<typename T>
vector<Pt<T>> convex_hull(vector<Pt<T>> a) {
  if(a.size() == 1) {
    return a;
  }
  sort(a.begin(), a.end());
  vector<Pt<T>> up {a[0]}, dw {a[0]};
  for(int i = 1; i < a.size(); ++i) {
    while(up.size() >= 2 && spin(up[up.size() - 2], up[up.size() - 1], a[i]) >= 0) {
      up.pop_back();
    }
    while(dw.size() >= 2 && spin(dw[dw.size() - 2], dw[dw.size() - 1], a[i]) <= 0) {
      dw.pop_back();
    }
    up.push_back(a[i]);
    dw.push_back(a[i]);
  }
  auto hull = move(dw);
  for(int i = (int) up.size() - 2; i >= 1; --i) {
    hull.push_back(up[i]);
  }
  return hull;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<Pt<long long>> a(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  long long ans = 0;
  auto cv = convex_hull(a); 
  int m = cv.size();
  for(int i = 0; i < m; ++i) {
    for(int j = (i + (m / 2 - 5) + 5 * m) % m, T = 10; T--; j = (j + 1) % m) {
      ans = max(ans, abs(cv[i].x - cv[j].x) + abs(cv[i].y - cv[j].y));
    }
  }
  cout << ans << '\n';
}