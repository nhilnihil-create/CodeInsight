#include <iostream>
#include <cmath>
#include <iomanip>
class Point{
  public:
    Point(){x=0,y=0;}
    Point(double x,double y){this->x=x,this->y=y;}
    double getX(){return x;}
    double getY(){return y;}
  private:
    double x,y;
};
int main(int argc, char const *argv[]) {
  double x1,x2,y1,y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  Point(x1,y1);
  Point(x2,y2);
  double horizon,vertical,distance;
  horizon = (x2-x1);
  if(horizon < 0)horizon*=(-1);
  vertical = (y2-y1);
  if(vertical < 0)vertical*=(-1);

  distance = sqrt(horizon*horizon+vertical*vertical);
  std::cout << std::fixed << std::setprecision(8) <<distance << std::endl;
  return 0;
}