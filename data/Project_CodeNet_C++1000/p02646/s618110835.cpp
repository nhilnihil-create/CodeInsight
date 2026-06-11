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
    ll a,b,v,w,t;
    cin >> a >> v >> b >> w >> t;

    if(abs(b-a) <= t*(v-w))
        pri("YES");
    else
        pri("NO");
    return 0;
}
