#include <iostream>
#include <map>
using namespace std;

map<string, string> weather = {{"Sunny", "Cloudy"},
                               {"Cloudy", "Rainy"},
                               {"Rainy", "Sunny"}};

int main()
{
  string S;
  cin >> S;
  cout << weather[S];
  return 0;
}