#include<iostream>
using namespace std;
int main()
{
    long long n, a, b, ans, rem;
    cin >> n >> a >> b;
    ans = n / (a + b) * a;
    rem = n % (a + b);
    ans += min(rem, a);
    cout << ans << " ";
    return 0;
}