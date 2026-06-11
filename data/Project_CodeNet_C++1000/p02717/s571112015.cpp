#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    swap(a, b);
    swap(a, c);

    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}
