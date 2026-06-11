#include <iostream>
using namespace std;

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    if (n & 1)
        cout << n / 2 + 1 << endl;
    else
        cout << n / 2 << endl;
}

int main()
{
    solve();
    return (0);
}



