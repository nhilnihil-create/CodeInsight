#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int d, t, s;
    cin >> d >> t >> s;
    float a;
    a = (float)d / s;
    if (a <= (float)t)
        cout << "Yes";
    else
    {
        cout << "No";
    }
    return 0;
}
