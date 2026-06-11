#include <iostream>

using namespace std;

int main()
{
int x, y;

for (x = 1; x<= 9; x++) {
for (y = 1; y<= 9; y++) {
cout << x << "x" << y << "=" << x*y<<endl;
}
}
}