#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int N;
    cin >> N;
    double ans = 0, tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        ans += 1 / tmp;
    }
    cout << fixed << setprecision(15) << 1 / ans;
}