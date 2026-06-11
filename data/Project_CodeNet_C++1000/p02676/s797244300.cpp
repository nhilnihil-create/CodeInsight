#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    ll K;
    string S;
    cin >> K;
    cin >> S;

    if (K >= S.size())
    {
        cout << S << endl;
    }
    else
    {
        cout << S.substr(0, K) << "..." << endl;
    }

    return 0;
}
