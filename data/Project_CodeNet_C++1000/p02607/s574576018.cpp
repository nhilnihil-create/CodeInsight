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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int count = 0;
    for(int i=0; i < n; i+=2)
    {
        if(a[i] % 2)
            ++count;
    }
    pri(count);
    return 0;
}
