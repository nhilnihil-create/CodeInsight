#include <iostream>
using namespace std;
 
int main() {
 int x, y, z;
 cin >> x >> y >> z;
 if (x + y + z >= 22)
   cout << "bust\n";
  else
    cout << "win\n";
}