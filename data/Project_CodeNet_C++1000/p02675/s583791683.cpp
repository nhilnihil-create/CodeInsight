#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    ll N;
    cin >> N;

    N %= 10;

    if (N == 2 || N == 4 || N == 5 || N == 7 || N == 9)
    {
        cout << "hon" << endl;
    }
    else if (N == 0 || N == 1 || N == 6 || N == 8)
    {
        cout << "pon" << endl;
    }
    else
    {
        cout << "bon" << endl;
    }

    return 0;
}
