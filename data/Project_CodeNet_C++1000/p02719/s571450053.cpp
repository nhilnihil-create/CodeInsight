#include <iostream>
using namespace std;

int main(void)
{
    long long n, k; cin >> n >> k;
    long long d = n % k;
    if (d <= k / 2) cout << d << endl;
    else cout << k - d << endl;
}