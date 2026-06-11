#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int64_t N, sum = 0;
    cin >> N;
    vector<int64_t> in(N), list(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> in[i];
        if (i % 2 == 0)
            list[0] += in[i];
        if (i % 2 == 1)
            list[0] -= in[i];
    }
    for (int i = 1; i < N; i++)
        list[i] = in[i - 1] * 2 - list[i - 1];
    for (auto x : list)
        cout << x << " ";
}