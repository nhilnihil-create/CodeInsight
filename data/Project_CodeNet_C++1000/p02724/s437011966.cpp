#include <iostream>
using namespace std;

int main()
{
  //int coin, thousand, fivehund,fiveyen, points;
  //thousand = 1000;
  //fivehund = 500;
  //fiveyen = 5;
  int coin, points;
  points = 0;
  cin >> coin;

  points = (coin / 500) * 1000;
  coin = coin % 500;
  points = points + (coin / 5) * 5;

  cout << points << endl;



}
