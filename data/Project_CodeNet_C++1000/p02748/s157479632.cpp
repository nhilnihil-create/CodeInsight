#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;
vector<int> num;

int main()
{
    int na, nb, m, mina = (1 << 30), minb = (1 << 30), x, y, c;
    cin >> na >> nb >> m;
    vector<int> a(na), b(nb);
    for (int i = 0; i < na; ++i)
    {
        cin >> a[i];
        mina = (min)(mina, a[i]);
    }
    for (int i = 0; i < nb; ++i)
    {
        cin >> b[i];
        minb = (min)(minb, b[i]);
    }
    int ans = mina + minb;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> c;
        --x, --y;
        int value = a[x] + b[y] - c;
        ans = (min)(ans, value);
    }
    cout << ans << endl;
    return 0;
}
