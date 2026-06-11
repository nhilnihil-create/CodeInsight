#include <iostream>

using namespace std;

int main()
{
    int K, i;
    int S = 0;

    cin >> K;

    for (int i = 0; i <= K; i++)
    {
        S = (S * 10 + 7) % K;
        if (S == 0)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}