#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
    int x,y,z;
    cin >> x >> y >> z;

    int tmp = 0;

    tmp = x;
    x = y;
    y = tmp;

    tmp = 0;

    tmp = x;
    x = z;
    z = tmp;

    cout << x << " " << y << " " << " " << z << endl;
}