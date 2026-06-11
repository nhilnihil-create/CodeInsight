#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 300005;

int n, m , ans;

int main()
{
    cin >> n >> m;
    ans = (n+m)*(n+m-1);
    ans/=2;
    ans-= (n*m);

    cout << ans;

    return 0;
}
