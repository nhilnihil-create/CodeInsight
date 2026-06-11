#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef unsigned long long ull; typedef unsigned int uint; typedef long double ld;

int main() { ios_base::sync_with_stdio(false); cin.tie(0);

int n;
cin >> n;
ll t;
ld ans = 1;
for (int i = 0; i < n; i++)
{
    cin >> t;
    if (ans != -1)
       ans *= t;
    if (ans > 1000000000000000000 || ans < 0)
       ans = -1;
    if (t == 0)
       ans = 0;
}
cout << (ll)ans;
return 0;
}