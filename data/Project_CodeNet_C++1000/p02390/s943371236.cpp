#include <iostream>
using namespace std;

int main()
{
    int t;

    cin >> t;

    int hour, min, sec;

    hour = t / 3600;
    min = t % 3600 / 60;
    sec = t % 60;

    cout << hour << ':' << min << ':' << sec << endl;

    return 0;
}