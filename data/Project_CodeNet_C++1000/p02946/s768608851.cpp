#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int K, X;
    cin >> K >> X;
    for (int i = X - K + 1; i < X + K; i++)
        cout << i << " ";
}