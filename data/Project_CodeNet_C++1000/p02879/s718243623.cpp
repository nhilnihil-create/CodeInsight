#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a > 9 || b > 9 || a < 1 || b < 1) cout << -1 << endl;
    else cout << a * b << endl;
}