#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{

    vector<int> v(5);
    rep(i, 5) cin >> v[i];

    rep(i, 5)
    {
        if (!v[i])
        {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}
