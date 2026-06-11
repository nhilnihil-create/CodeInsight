#include <iostream>
#include <math.h>

using namespace std;

class Point
{
private:
  double x;
  double y;
public:
  void setX(double x);
  void setY(double y);
  double getX();
  double getY();
};

void Point::setX(double a) {
  x = a;
}

void Point::setY(double a) {
  y = a;
}

double Point::getX() {
  return x;
}

double Point::getY() {
  return y;
}

int main() {
  double px, py, qx, qy;
  Point p, q;
  cin >> px >> py >> qx >> qy;
  p.setX(px);
  p.setY(py);
  q.setX(qx);
  q.setY(qy);
  cout << fixed << sqrt(pow(p.getX()-q.getX(), 2)+pow(p.getY()-q.getY(), 2)) << endl;
  return 0;
}