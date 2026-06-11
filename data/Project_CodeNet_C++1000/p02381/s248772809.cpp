/**
 * Distance.cpp
 * Create:20180502
 * Description:標準偏差を求めるプログラム
 */
#include <iostream>
#include <cmath>
#include <vector>

/**
 * 平均を求める関数
 * @param  vec 点数を格納した配列
 * @return     平均値
 */
double average(std::vector<int> vec){
  double sum = 0;
  for (int i:vec){
    sum += (double)i;
  }
  double ave = sum / vec.size();
  return ave;
}

/**
 * 標準偏差を求める関数
 * @param  vec 点数を格納した配列
 * @return     標準偏差
 */
double deviation(std::vector<int> vec){
  double ave = average(vec);
  double dev = 0.0;
  for (int i:vec){
    double tmp = (double)i - ave;
    dev += pow(tmp, 2);
  }
  dev = dev / vec.size();
  return sqrt(dev);
}

int main(int argc, char* argv[]){
  std::vector<double> result;

  while (true){
    int count;
    std::cin >> count;
    if (count == 0)
      break;

    std::vector<int> points;
    for (int i = 0; i < count; i++){
      int point;
      std::cin >> point;
      points.push_back(point);
    }

    double dev = deviation(points);
    result.push_back(dev);
  }

  for (double d:result){
    printf("%.8f\n", d);
  }

  return 0;
}
