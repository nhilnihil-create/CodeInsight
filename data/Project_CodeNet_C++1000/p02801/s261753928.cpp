#include <iostream>
using namespace std;

int main()
{
  int number;
  number = 0;
  char input;
  char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  cin >> input;

  for (int i = 0; i < 26; i++)
  {
    if(input == alphabet[i])
    {
      number = i;
    }
  }

  cout << alphabet[number + 1] << endl;

}
