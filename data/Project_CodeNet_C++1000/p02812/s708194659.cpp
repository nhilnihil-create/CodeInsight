#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    int cnt = 0;
    rep(i, N)
    {
        if (S.substr(i, 3) == "ABC")
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}