#include <iostream>

using namespace std;

int main(void)
{
    long long A, B, K;
    cin >> A >> B >> K;
    long long a1;
    long long b1;
    if (A >= K)
    {
        a1 = A - K;
        b1 = B;
    }
    else
    {
        a1 = 0;
        b1 = max(0ll,B - (K - A));
    }

    cout << a1 << " " << b1 << endl;

    return 0;
}
