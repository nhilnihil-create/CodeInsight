#include <bits/stdc++.h>
#define long long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int main()
{
    fastio;
    long n;
    cin >> n;
    n--;
    long s = 0;
    for (long i = 1; i <= n; i++)
    {
        s += n/i;
    }
    cout << s;
}
