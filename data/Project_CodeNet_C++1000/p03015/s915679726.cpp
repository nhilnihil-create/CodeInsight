#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long int ll;
string S;
int main()
{
    cin >> S;
    ll len = S.size(), mod = 1e9 + 7, ans = 1;
    for (ll i = len - 1, d = 1; i >= 0; i--, d = d * 3 % mod) {
        if (S.at(i) == '1') ans = (ans * 2 + d) % mod;
    }
    cout << ans << "\n";
}