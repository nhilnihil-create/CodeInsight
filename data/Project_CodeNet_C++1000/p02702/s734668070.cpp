#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


string s;
long long f[2019];
long long p = 1;
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    f[0]++;
    long long x=0;
    for (int i = s.size()-1; i >= 0; i--)
    {
        x = ((s[i] - '0') * p + x) % 2019;
        ans += f[x];
        f[x]++;
        p = (p*10)%2019;

    }
    cout << ans;
    return 0;
}
