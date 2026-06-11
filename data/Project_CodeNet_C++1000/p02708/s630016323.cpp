#include <iostream>
#include <vector>

using namespace std;


int main()
{
    const int64_t mod = 1000000000 + 7;

    int N, K;
    cin >> N >> K;

    int64_t res = 0;

    for (int i = 0; i < K; ++i)
    {
        res += (N - i - i);
    }

    int64_t sum = (res + 1) % mod;
    for (int k = K; k < N + 1; ++k)
    {
        res += (N - k - k);
        sum += res + 1;
        sum %= mod;
    }
    cout << sum << endl;
}