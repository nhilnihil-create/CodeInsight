#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    for (int i = 0; i < b; i++)
    {
        s += a + '0';
    }

    cout << s << endl;
}