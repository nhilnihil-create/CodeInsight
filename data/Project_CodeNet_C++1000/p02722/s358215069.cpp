#include<iostream>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
    long long n, num = 1;
    cin >> n;
    if (n > 2)
        num++;
    for (long long k = 2; k <= sqrt(n); k++)
    {
        if ((n - 1) % k == 0)
            num += 2;
        if (k * k == n - 1)
            num--;
        
        long long m = n;
        if (n % k == 0)
        {
            while (m >= k)
                if (m % k == 0)
                    m /= k;
                else
                    m %= k;
            if (m == 1)
                num++;
        }
    }

    cout << num << endl;
    return 0;
}