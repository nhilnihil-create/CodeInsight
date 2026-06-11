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
    int l, r, d; cin >> l >> r >> d;
    int count = 0;
    for(int i=1; i < 101; ++i)
    {
        int j = d*i;
        if(l <= j && j <= r)
            ++count;
    }
    pri(count);
    return 0;
}