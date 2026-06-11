#include <iostream>

using namespace std;

int main()
{
  string palabra;
  string firstSide = "";
  string secondSide = "";
  cin >> palabra;

  int n = palabra.length();
  for (int i = 0; i < (n - 1) / 2; i++)
  {
    firstSide += palabra[i];
  }

  for (int i = ((n + 3) / 2) - 1; i < n; i++)
  {
    secondSide += palabra[i];
  }

  if (firstSide == secondSide)
    cout << "Yes";
  else
    cout << "No";

  return 0;
}