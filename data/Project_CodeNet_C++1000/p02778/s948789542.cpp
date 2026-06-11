#include <iostream>
#include <string>

using namespace std;

int main()
{
  string org;
  string xxx = "";
  cin >> org;
  for (int i = 0; i < org.size(); i++)
  {
    xxx += "x";
  }
  cout << xxx << endl;
}