#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll a,b;
    cin >> a >> b;
    if(a <= 9 && b <= 9) cout << a*b << endl;
    else  cout << -1 << endl;

    return 0;
}