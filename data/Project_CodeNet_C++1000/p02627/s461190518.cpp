#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char alpha;
  cin >> alpha;
  if(alpha == toupper(alpha))
  {
    cout << "A" << endl;
  }
  else
  {
    cout << "a" << endl;
  }
}
