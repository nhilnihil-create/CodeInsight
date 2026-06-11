#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct point{
  double x,y;
  public:
  point(const point &p):x(p.x),y(p.y){}
  point():x(0),y(0){}
  point(double x,double y):x(x),y(y){}

  double get_x()const{ return x; }
  double get_y()const{ return y; }

  point& operator=(const point &p){
    x = p.x;
    y = p.y;
    return *this;
  }

  point operator+(const point &p)const{
    return point(x+p.x,y+p.y);
  }


  point operator-(const point &p)const{
    return point(x-p.x,y-p.y);
  }

  point operator*(const double k)const{
    return point(k*x,k*y);
  }

  double norm()const{
    return sqrt(x*x+y*y);
  }

  double dist(const point &p)const{
    return (*this-p).norm();
  }

  void show()const{ cout << setprecision(6) << x << " " << y << endl; }
};

void print_kochcurve(const point &p1,const point &p2,int n);

int main(){
  int n;
  cin >> n;
  point p1(0,0),p2(100,0);
  p1.show();
  print_kochcurve(p1,p2,n);

  return 0;
}

void print_kochcurve(const point &p1,const point &p2,int n){
  if(n==0){
    p2.show();
    return;
  }

  point s,t,u;

  s = (p1*2.0 + p2)*(1./3);
  t = (p1 + p2*2.0)*(1./3);

  u = (p1 + p2)*(1./2);
  double len = p1.dist(s)*sqrt(3)/2;
  point v = p2-p1;
  point tmp(-v.get_y(),v.get_x());
  tmp = tmp*(1./tmp.norm());

  u = u + tmp*len;

  print_kochcurve(p1,s,n-1);
  print_kochcurve(s,u,n-1);
  print_kochcurve(u,t,n-1);
  print_kochcurve(t,p2,n-1);

}