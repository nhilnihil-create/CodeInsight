#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

using namespace std;

int main ()
{
    double N,X;
    const double taxrate = 1.08;

    cin >> N;
    X = N / taxrate;
    while ((int)X <= (int)N)
    {
        if ((int)((int)X*1.08) == (int)N)
        {
            cout << (int)X << endl;
            return 0;
        }
        X += 1.0;            
    }

    cout << ":(" << endl;
    return 0;
}