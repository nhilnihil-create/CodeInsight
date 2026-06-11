#include <iostream>
#include <cmath>
#include <string>

#define START 100

using namespace std;

int main()
{
  int year;
  long x, money, value;

  cin >> x;

  money = START; year = 0;

  while(money < x){
    value = money / 100;
    money += value;
    year++;
  }


  cout << year;

}
