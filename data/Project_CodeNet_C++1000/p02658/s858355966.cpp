#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long N;
    bool breakFlag = false;
    bool zeroFlag = false;
    long double res = 1;
    long long ans;
    cin >> N;
    vector<long long> A(N, 0);
    for (long long i = 0; i < N; i++)
    {
        cin >> A.at(i);
        if (A[i] == 0)
        {
            zeroFlag = true;
        }
    }
    if (zeroFlag) {
        cout << 0 << endl;
        return 0;
    }
    for (long long i = 0; i < N; i++)
    {
        res *= A[i];
        if (res > 1000000000000000000)
        {
            breakFlag = true;
            break;
        }
    }
    if (breakFlag)
    {
        cout << -1 << endl;
    }
    else
    {
        ans = res;
        cout << ans << endl;
    }
    return 0;
}