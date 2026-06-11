#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    ll X;
    cin >> X;

    ll A, B;
    for (A = -120; A < 120; A++)
    {
        for (B = -120; B < 120; B++)
        {
            if (pow(A, 5) - pow(B, 5) == X)
            {
                printf("%lld %lld\n", A, B);
                return (0);
            }
        }
    }
    return (0);
}