#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    // 4a + 2b = y
    // a + b = x
    // 2a + 2b = 2x
    // 2a = y - 2x
    // a = (y - 2x) / 2
    int a = (y - 2 * x) / 2;
    int b = x - a;
    yorn (a >= 0 && b >= 0 && 4 * a + 2 * b == y)
    return 0;
}