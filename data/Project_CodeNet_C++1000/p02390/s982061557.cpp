#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int m = t / 60;
    int h = m / 60;
    t %= 60;
    m %= 60;

    cout << h << ':' << m << ':' << t << endl;

}