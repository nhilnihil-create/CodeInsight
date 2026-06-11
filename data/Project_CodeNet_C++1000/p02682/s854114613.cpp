#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

int main(void)
{
    ll a,b,c,k,sum=0;
    cin >> a >> b >> c >> k;
    while(k>0 && a>0)
    {
        sum++;
        k--;
        a--;
    }
    while(k>0 && b>0)
    {
        k--;
        b--;
    }
    while(k>0 && c>0)
    {
        sum--;
        k--;
        c--;
    }
    cout << sum << endl;
    return 0;
}
