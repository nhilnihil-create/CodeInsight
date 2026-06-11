#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iterator>
#include <numeric>
#include <functional>
#include <climits>



using namespace std;
typedef unsigned long long ull;
typedef long long ll;

const double cos60 = cos(M_PI/3);
const double sin60 = sin(M_PI/3);
const double cos120 = cos(2*M_PI/3);
const double sin120 = sin(2*M_PI/3);

class point{
private:
  double x, y;
public:
  point(): x(0), y(0) {}
  point(double x_, double y_): x(x_), y(y_) {}
  point rot60(){
    double a = cos60 * x - sin60 * y;
    double b = sin60 * x + cos60 * y;
    return point(a, b);
  }
  point rot120(){
    double a = cos120 * x - sin120 * y;
    double b = sin120 * x + cos120 * y;
    return point(a, b);    
  }
  point plus(point p){
    return point(p.x + x, p.y + y);
  }
  point mul(double a){
    return point(a*x, a*y);
  }
  point rot60(point p){
    return this->plus(p.mul(-1)).rot60().plus(p);
  }
  point rot120(point p){
    return this->plus(p.mul(-1)).rot120().plus(p);
  }
  void print(){
    cout << setprecision(10) << x << " " << y << endl;
  }
};

vector<point> koch(point p, point q){
  point q_p = q.plus(p.mul(-1));
  point a = p.plus(q_p.mul(1.0/3));
  point b = p.plus(q_p.mul(2.0/3));
  point c = q_p.mul(1.0/3).rot60().plus(a);
  vector<point> ret(4);
  ret[0] = p;
  ret[1] = a;
  ret[2] = c;
  ret[3] = b;
  return ret;
}
vector<point> koch(vector<point> v, int n){
  if(n == 0) return v;
  vector<point> ret(v.size() + (v.size()-1) * 3);
  size_t pos = 0;
  for (size_t i = 0; i < v.size()-1; i++) {
    vector<point> buf = koch(v[i], v[i+1]);
    for (size_t j = 0; j < buf.size(); j++) {
      ret[pos++] = buf[j];      
    }
  }
  ret.back() = v.back();
  return koch(ret, n-1);
}

int main(int argc, char *argv[]){
  point p(0,0);
  point q(100, 0);
  vector<point> v(2);
  v[0] = p;
  v[1] = q;
  int n;
  cin >> n;
  vector<point> ret = koch(v, n);
  for (size_t i = 0; i < ret.size(); i++) {
    ret[i].print();
  }

  
  return 0;
}