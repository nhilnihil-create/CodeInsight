#include <iostream>

using namespace std;

int main(void)
{
  int K , R;
  cin >> K >> R;
  if(K < 10 ) 
  {
    cout << R + 100*(10-K) << endl;
  }
  else
  {
    cout << R << endl;
  }
}