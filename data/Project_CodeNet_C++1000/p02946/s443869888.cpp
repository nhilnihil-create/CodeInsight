#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

int solve(int N, const vector<int>& xs)
{
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    int K, X;
    cin >> K >> X;

    for (int i = X - K + 1; i < X + K - 1; ++i)
        cout << i << ' ';

    cout << X + K - 1 << endl;

    return 0;
}
