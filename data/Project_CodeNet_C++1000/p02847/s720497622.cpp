#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll solve(int N, const vector<ll>& xs)
{
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<string> days { "", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    auto i = find(days.begin(), days.end(), s) - days.begin();

    cout << 8 - i << endl;

    return 0;
}
