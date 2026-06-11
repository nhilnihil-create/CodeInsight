#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/* Point */
class Point
{
private:
  double x;
  double y;

public:
  Point(double a, double b):
    x(a), y(b)
  {}

  Point rotate()
  {
    double temp_x = x;
    double temp_y = y;
    temp_x = (1.0 / 2.0) * x - (sqrt(3.0) / 2.0) * y;
    temp_y = (sqrt(3.0) / 2.0) * x + (1.0 / 2.0) * y;
    return Point(temp_x, temp_y);
  }

  friend Point operator+(const Point& p1, const Point& p2);
  friend Point operator-(const Point& p1, const Point& p2);
  friend Point operator*(const Point& p, const double& n);
  friend ostream& operator<<(ostream& os, const Point& p);
};

Point operator+(const Point& p1, const Point& p2)
{
  return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator-(const Point& p1, const Point& p2)
{
  return Point(p1.x - p2.x, p1.y - p2.y);
}

Point operator*(const Point& p, const double& n)
{
  return Point(p.x * n, p.y * n);
}

ostream& operator<<(ostream& os, const Point& p)
{
  os << fixed << setprecision(8) << p.x << ' ' << p.y;
  return os;
}

// Generate a triangle in a line
vector<Point> gen_triangle(const Point& p1, const Point& p2)
{
  Point pa = p1 + ((p2 - p1) * (1.0 / 3.0));
  Point pc = p1 + ((p2 - p1) * (2.0 / 3.0));
  Point pb = pa + (pc - pa).rotate();
  return vector<Point>{pa, pb, pc};
}

// Generate triangles along the specified points
vector<Point> iterate_triangle(vector<Point> points)
{
  vector<Point> result;
  for (vector<Point>::const_iterator itr = points.begin(); itr != points.end() - 1; ++itr)
  {
    result.push_back(*itr);
    vector<Point> buffer = gen_triangle(*itr, *(itr + 1));
    for (int i = 0; i < 3; ++i)
    {
      result.push_back(buffer.at(i));
    }
  }
  result.push_back(*(points.end() - 1));

  return result;
}

// Generate Koch Curve
vector<Point> gen_koch(const int& n)
{
  if (n == 0)
  {
    return vector<Point>{Point{0, 0}, Point{100, 0}};
  }
  else
  {
    return iterate_triangle(gen_koch(n - 1));
  }
}

int main()
{
  int n;
  cin >> n;
  vector<Point> v = gen_koch(n);

  for (vector<Point>::const_iterator itr = v.begin(); itr != v.end(); ++itr)
  {
    cout << *itr << endl;
  }

  return 0;
}

