#include <bits/stdc++.h>
using namespace std;

int main()
{
    int64_t S;
    cin >> S;

    int64_t X1 = 0, Y1 = 0, X2 = 1e9, Y2 = 1;
    int64_t X3 = (X2 - (S % X2)) % X2;
    int64_t Y3 = (S + X3) / X2;
    cout << X1 << " " << Y1 << " ";
    cout << X2 << " " << Y2 << " ";
    cout << X3 << " " << Y3 << endl;
}