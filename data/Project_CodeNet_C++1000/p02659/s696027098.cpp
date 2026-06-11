#include <iostream>
using namespace std;

int main(void)
{
    long long a; cin >> a;
    float b; cin >> b;
    long long c = (b + 1e-3) * 100;
    long long prod = a * c;
    long long ans = prod / 100;
    cout << ans << endl;
}