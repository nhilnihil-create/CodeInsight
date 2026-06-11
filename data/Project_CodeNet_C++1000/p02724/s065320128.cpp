#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int x;
    cin >> x;
    int mod = x;
    int ans = 0;
    ans += (mod / 500) * 1000;
    mod = x % 500;
    ans += (mod / 5) * 5;
    cout << ans << endl;
    return 0;
}
