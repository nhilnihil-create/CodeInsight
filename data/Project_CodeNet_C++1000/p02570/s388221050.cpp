#include <bits/stdc++.h>
using namespace std;
int main()
{
    float x, y, z;
    cin >> x >> y >> z;
    if (x / z <= y)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}