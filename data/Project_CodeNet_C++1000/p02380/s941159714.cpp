#include <iostream>
#include <cmath>

using namespace std;

int main() {

   double a{}, b{}, c{}, q{};

   cin >> a >> b >> q;
   q *= M_PI / 180;
   c = sqrt(a * a + b * b - 2 * a * b * cos(q));

   double S{}, L{}, h{};

   h = b * sin(q);
   S = a * h / 2;
   L = a + b + c;

   cout << fixed << S << endl;
   cout << fixed << L << endl;
   cout << fixed << h << endl;

   return 0;

}