#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  if (s == "Sunny")
    cout << "Cloudy" << endl;
  else if (s == "Cloudy")
    cout << "Rainy" << endl;
  else
    cout << "Sunny" << endl;
  return 0;
}
