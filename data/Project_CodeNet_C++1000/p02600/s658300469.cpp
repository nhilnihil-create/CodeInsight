#include <iostream>
using namespace std;

int main()
{
  int rating, kyu;

  cin >> rating;
  if(rating >= 400 && rating <= 599)
  {
    kyu = 8;
  }

  if(rating >= 600 && rating <= 799)
  {
    kyu = 7;
  }

  if(rating >= 800 && rating <= 999)
  {
    kyu = 6;
  }

  if(rating >= 1000 && rating <= 1199)
  {
    kyu = 5;
  }

  if(rating >= 1200 && rating <= 1399)
  {
    kyu = 4;
  }

  if(rating >= 1400 && rating <= 1599)
  {
    kyu = 3;
  }

  if(rating >= 1600 && rating <= 1799)
  {
    kyu = 2;
  }

  if(rating >= 1800 && rating <= 1999)
  {
    kyu = 1;
  }

  cout << kyu << endl;
}
