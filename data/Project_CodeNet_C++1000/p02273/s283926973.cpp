//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=jp
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

class Position{
//private:
  public:
  double x;
  double y;
  int get_x(){return x;}
  int get_y(){return y;}
  void setdata(double a, double b){ x = a; y = b;}
  void disp(){printf("%.8lf %.8lf\n", x, y);}
};

void koch(int n, Position P0, Position P1){
  const double co = cos(M_PI/3);
  const double si = sin(M_PI/3);
  Position S,T,U;
  if(n == 0){
  }else{
    S.setdata((2*P0.x+P1.x)/3, (2*P0.y+P1.y)/3);
  //S.disp();
    T.setdata((P0.x+2*P1.x)/3, (P0.y+2*P1.y)/3);
    //T.disp();
    double ux = (T.x-S.x)*co - (T.y-S.y)*si + S.x;
    double uy = (T.x-S.x)*si + (T.y-S.y)*co + S.y;
    U.setdata(ux, uy);
    koch(n-1, P0, S);
    S.disp();
    koch(n-1, S, U);
    U.disp();
    koch(n-1, U, T);
    T.disp();
    koch(n-1, T, P1);
  }
}


int main(){
  Position First, Last;
  First.setdata(0, 0);
  Last.setdata(100, 0);
    int n;
  cin >> n;
  First.disp();
  koch(n, First, Last);
  Last.disp();
}