#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ll n, a = 100LL;
    cin >> n;
    int cnt = 0;
    while (a < n)
    {
        a += a / 100LL;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
