#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    ll a, b;
    cin >> a >> b;

    cout << n/(a+b)*a + min(n%(a+b), a) << endl;


    return 0;
}