#include <iostream>
using namespace std;
int main()
{
    long long n, ans = 0, k = 10;
    cin >> n;
    if(n & 1){
        cout << 0 << endl;
        return 0;
    }
    while (k <= n) {
        ans += n / k;
        k *= 5;
    }
    cout << ans << endl;
    return 0;
}