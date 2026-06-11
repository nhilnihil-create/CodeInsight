#include <iostream>
using namespace std;

int main(void)
{
    long long a, b, n; cin >> a >> b >> n;
    long long d = min(b-1 , n);
    long long ans = (a * d) / b;
    cout << ans << endl;
}