#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
#define pri(str) cout << str << endl
using ll = long long;
using P = pair<int, int>;

const ll MX = 1e18;
const long double PI = acos(-1);

int main()
{
    int d, t, s; cin >> d >> t >> s;
    if( d <= s*t )
    {
        pri("Yes");
    }
    else
    {
        pri("No");
    }
    return 0;
}
