/**
 * Distance.cpp
 * Create:20180430
 * Description:２点間の距離を求めるプログラム
 */
#include <iostream>
#include <cmath>

/**
 * 座標クラス
 * @param x x座標
 * @param y y座標
 */
class Point{
private:
  double x;
  double y;
public:
  /**
   * コンストラクタ
   * @param x x座標
   * @param y y座標
   */
  Point(double x, double y){
    this->x = x;
    this->y = y;
  }

  /**
   * x座標
   * @return x座標
   */
  double get_x(){
    return x;
  }

  /**
   * y座標
   * @return y座標
   */
  double get_y(){
    return y;
  }
};

/**
 * 距離計算関数
 * @param  a 座標１
 * @param  b 座標２
 * @return   2点間の距離
 */
double distance(Point a, Point b){
  double width = a.get_x() - b.get_x();
  double height = a.get_y() - b.get_y();
  double hypotenuse = pow(width,2) + pow(height,2);
  return sqrt(hypotenuse);
}

int main(int argc, char* argv[]){
  double x1, y1, x2, y2;

  std::cin >> x1 >> y1 >> x2 >> y2;
  Point a = Point(x1, y1);
  Point b = Point(x2, y2);

  printf("%.8f", distance(a, b));

  return 0;
}
