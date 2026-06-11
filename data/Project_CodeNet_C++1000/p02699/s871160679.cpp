#include <iostream>
using namespace std;

void sandw()
{
  int sheep, wolf;
  cin >> sheep >> wolf;

  if(sheep > wolf)
  {
    cout << "safe" << endl;
  }
  else
  {
    cout << "unsafe" << endl;
  }
}

int main()
{
  sandw();
}
