#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int N, D;
    cin >> N >> D;
    cout << (N + D * 2) / (D * 2 + 1);
}