#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string N;
    cin >> N;

    reverse(N.begin(), N.end());

    vector<vector<int64_t>> dp(N.length() + 1, vector<int64_t>(2, INT_MAX));
    dp.at(0).at(0) = 0;
    dp.at(0).at(1) = INT_MAX;
    for (int i = 0; i < N.length(); i++)
    {
        char c = N.at(i) - '0';
        dp.at(i + 1).at(0) = min(dp.at(i).at(0) + c, dp.at(i).at(1) + c);
        dp.at(i + 1).at(1) = min(dp.at(i).at(0) + (10 - c) + 1, dp.at(i).at(1) + (9 - c));
    }
    cout << min(dp.at(N.length()).at(0), dp.at(N.length()).at(1)) << endl;
}