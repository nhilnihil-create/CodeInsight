#include <iostream>
using namespace std;

int main()
{
  int pages, number;
  number = 0;
  cin >> pages;

  number = (pages % 2) + (pages / 2);
  cout << number << endl;
}
