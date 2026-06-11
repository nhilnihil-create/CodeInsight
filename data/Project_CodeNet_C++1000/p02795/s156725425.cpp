#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double rows, columns, blocks, number;
  number = 0;
  cin >> rows >> columns >> blocks;

  if(rows > columns)
  number = rows;
  else
  number = columns;

  cout << ceil(blocks / number) << endl;


}
