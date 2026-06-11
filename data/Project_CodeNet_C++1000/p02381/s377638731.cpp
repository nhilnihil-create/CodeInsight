#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int main(int argc, char* argv[])
{
  vector<double> scores;
  double average,distance,number,value;
  while(1)
    {
    average=0;
    distance=0;
    cin >> number;
    if(number==0) break;
    for(int i=0;i<number;i++)
    {
      cin >> value;
      average+=value/number;
      scores.push_back(value);
    }
    for(auto s:scores)
    {
      distance+=pow(s-average,2.0);
    }
    printf("%.8lf\n",sqrt(distance/number));
    scores.clear();
  }
}