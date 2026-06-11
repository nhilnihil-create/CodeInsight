#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    double A, B, X, rad;
    cin >> A >> B >> X;
    if (X < A * A * B / 2)
    {
        rad = atan((A * B * B) / (X * 2));
    }
    else
    {
        X = A * A * B - X;
        rad = atan((X * 2) / (A * A * A));
    }

    cout << fixed << setprecision(10) << rad * (180 / PI);
}