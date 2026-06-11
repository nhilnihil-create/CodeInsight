#include <iostream>
#include <string>

#define ll long long
#define repeat(i, x) for(register ll i = 0; i < x; i++)

using namespace std;

int main()
{
  int K, X;
  cin >> K >> X;

  cout << ((500 * K >= X) ? "Yes" : "No") << endl; 
}