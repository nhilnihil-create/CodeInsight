#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;

    long long val1 = N % K;
    long long val2 = (N / K + 1) * K - N;
    cout << min(val1, val2) << endl;
    return 0;
}