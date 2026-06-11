#include <iostream>
using namespace std;

int main()
{
  int count;
  count = 1;
  int numbers[5];
  for(int i = 0; i < 5; i++)
  {
    cin >> numbers[i];
  }

  for(int i = 0; i < 5; i++)
  {
    if(numbers[i] == 0)
    break;
    else
    count++;
  }

  cout << count << endl;

}
