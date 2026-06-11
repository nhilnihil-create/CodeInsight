#include <iostream>

using namespace std;

int main()
{
    int y ;
    cin>> y;
    int res = 0;
    res += y /500 * 1000;

    y =y - y/500  *500;

    res += y / 5 * 5;
    cout<< res;
}
