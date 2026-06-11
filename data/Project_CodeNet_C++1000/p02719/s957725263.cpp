#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    long long a, b;
    a = N % K;
    b = abs(K - a);
    long long ans;
    if (a<b)
    {
        ans = a;
    }else{
        ans = b;
    }

    cout << ans << endl;
}