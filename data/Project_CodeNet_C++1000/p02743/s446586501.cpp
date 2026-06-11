#include <bits/stdc++.h>
using namespace std;

int main()
{

    long double a, b, c, X, Y;

    cin >> a >> b >> c;

    if(c-a-b<0){
        cout << "No";
        return 0;
    }

    X = a + b - c;

    X *= X;
    Y = 4 * a * b;


    if (Y<X)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
