#include <iostream>
using namespace std;

int multiple()
{
  int num1, num2, result;
  cin >> num1 >> num2;
  result = num1 * num2;
  return result;
}

int main()
{
  cout << multiple() << endl;
}
