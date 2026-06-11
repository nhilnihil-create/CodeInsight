#include <iostream>
using namespace std;
int main()
{
    long long n, sub = 10, ans = 0, sub2 = 50, sub4 = 2;
    cin >> n;
    if(n % 2 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        while(sub <= n)
        {
            ans += n / sub;
            sub *= 5;
        }
        cout << ans << endl;
    }
    return 0;
}
