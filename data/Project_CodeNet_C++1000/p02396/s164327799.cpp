#include <iostream>

using namespace std;

int main()
{
int i;
int a;

for(i=0;i<10000;i++)
  {
    cin >> a;
    cout << "Case " << i+1 << ": " << a <<"\n";
  }
}