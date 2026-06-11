#include <iostream>
#include<deque>
#include<numeric>
using namespace std;

int main()
{

    int N;
    cin >> N;
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {

        for (int k = 1; k <= N;++k)
            for (int m = 1; m <= N;++m)
                    ans += gcd(gcd(i,k),m);
    }

    cout << ans << endl;
}