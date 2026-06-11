#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    long long n, k;
    cin >> n >> k;

    long long ans = 0;
    for (long long i = k; i <= n+1; i++)
    {
        long long max = (2 * n - i + 1)*i/2;
        //If i is int, the result of (i-1)*i becomes int and the value will be messed up 
        long long min = (i-1)*i/2;
        long long tmp = max - min + 1;
        ans = (ans + tmp) % 1000000007;
    }

    cout << ans << endl;

    return 0;
}