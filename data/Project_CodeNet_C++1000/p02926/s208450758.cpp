#include <iostream>
#include <cmath>

namespace Geometry {
  using Float = long double;
  using Real = long long;
  constexpr Float eps = 1e-9;

  namespace Plane {
    struct Vec {
      Real x, y;
      constexpr Vec() : x(0), y(0) {}
      constexpr Vec(Real k) : x(k), y(k) {}
      constexpr Vec(Real x, Real y) : x(x), y(y) {}
      static constexpr Real dot(Vec v, Vec w) { return v.x*w.x + v.y*w.y; }
      static constexpr Real cross(Vec v, Vec w) { return v.x*w.y - v.y*w.x; }
      static constexpr Vec rot(Vec v, Vec w) { return Vec(v.x*w.x - v.y*w.y, v.x*w.y + v.y*w.x); }
      constexpr Real norm2() const { return x*x+y*y; }
      Float norm() const { return std::sqrt(x*x+y*y); }
      Float arg() const { return std::atan2(x, y); }
      constexpr Vec& operator+=(Vec const& v) { x += v.x; y += v.y; return *this; }
      constexpr Vec& operator-=(Vec const& v) { x -= v.x; y -= v.y; return *this; }
      constexpr Vec& operator*=(Real const& k) { x *= k; y *= k; return *this; }
      constexpr Vec& operator*=(Vec const& v) { x *= v.x; y *= v.y; return *this; }
      constexpr Vec operator-() const { return Vec(-x, -y); }
      friend constexpr Vec operator+(Vec const& v, Vec const& w) { return Vec(v) += w; }
      friend constexpr Vec operator-(Vec const& v, Vec const& w) { return Vec(v) -= w; }
      friend constexpr Vec operator*(Real const& k, Vec const& v) { return Vec(v) *= k; }
      friend constexpr Vec operator*(Vec const& v, Vec const& w) { return Vec(v) *= w; }
      constexpr int ort() const { // orthant
        // if(abs(x) < eps && abs(y) < eps) return 0;
        if(  x>0  && !(y<0)) return 1; //  x>0 && y>=0
        if(!(x>0) &&   y>0 ) return 2; // x<=0 &&  y>0
        if(  x<0  && !(y>0)) return 3; //  x<0 && y<=0
        if(!(x<0) &&   y<0 ) return 4; // x>=0 &&  y<0
        return 0;
      }
      friend constexpr bool operator<(Vec const& a, Vec const& b) {
        int ao = a.ort() , bo = b.ort();
        if(ao != bo) return ao < bo;
        //if(ao == 0) return false;
        return 0 < cross(a, b);
      }
      friend std::istream& operator>>(std::istream& is, Vec& v) noexcept { is >> v.x >> v.y; return is; }
      friend std::ostream& operator<<(std::ostream& os, Vec const& v) noexcept { os << '(' << v.x << ',' << v.y << ')'; return os; }
    };

  }
}
using Geometry::Plane::Vec;

#include <iomanip>
#include <algorithm>
#include <vector>

signed main() {
  using namespace std;

  // abc139_f
  int n; cin >> n;

  vector<Vec> v(n);
  for(int i=0; i<n; ++i) cin >> v[i];

  sort(v.begin(), v.end());
  // for(int i=0; i<n; ++i) cerr << v[i] << ' '; cerr << endl;

  long long ans = 0;
  Vec now{};
  for(int l=0,r=0; l<n; ++l) {
    while(r-l<n) {
      if((now+v[r%n]).norm2() < now.norm2()) break;
      now += v[r%n];
      ++r;
    }
    // cerr << l << ' ' << r << ' ' << now << endl;
    if(ans < now.norm2()) ans = now.norm2();
    now -= v[l];
  }

  cout << fixed << setprecision(15) << sqrt(ans) << endl;

  return 0;
}