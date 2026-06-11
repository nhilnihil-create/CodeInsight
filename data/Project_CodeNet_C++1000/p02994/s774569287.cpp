#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int N, L;
    cin >> N >> L;
    int min = L, max = L + N - 1;
    int eat;
    if (0 < min)
        eat = min;
    else if (max < 0)
        eat = max;
    else
        eat = 0;
    cout << ((min + max) * N / 2) - eat;
}