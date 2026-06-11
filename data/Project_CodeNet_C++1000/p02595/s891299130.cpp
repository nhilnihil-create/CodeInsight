#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N;
    int ans = 0;
    long long D;
    vector<long long> X(200000);
    vector<long long> Y(200000);

    cin >> N >> D;

    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (X[i] * X[i] + Y[i] * Y[i] <= D * D)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}