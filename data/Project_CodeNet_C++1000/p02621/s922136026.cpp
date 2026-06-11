#include <iostream>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;

    ll ans = n + (n*n) +(n*n*n);

    cout << ans << endl;
}
