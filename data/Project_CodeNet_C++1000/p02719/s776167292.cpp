#include <iostream>

using namespace std;

int main()
{
    long long int N, K;
    cin >> N >> K;

    if (N % K > (double)K / 2)
    {
        cout << K - N % K;
    }
    else
        cout << N % K;

    return 0;
}