#include <iostream>
using namespace std;


long long int gcd(long long int x, long long int y)
{
    if (x % y == 0) {
        return y;
    } else {
       gcd(y, x%y);
    }
}

int main()
{
    long long int a,b,c,d;
    cin >> a >> b >> c >> d;
    long long int ans_a, ans_b;
    long long int y = gcd(c, d);

    ans_a = (a-1) - ((a-1)/c) - ((a-1)/d) + (a-1)/((c*d)/y);
    ans_b = b - (b/c) - (b/d) + b/((c*d)/y);

    cout << ans_b - ans_a << endl;

    return 0;
}