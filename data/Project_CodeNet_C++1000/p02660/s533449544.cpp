#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

std::map<long long, long long> PrimeFactorization(long long iValue)
{
    std::map<long long, long long> result;
    long long rootValue = sqrt(iValue);
    long long tmpValue = iValue;
    for (long long i = 2; i <= rootValue; i++)
    {
        int divisionCnt = 0;
        while (tmpValue % i == 0)
        {
            tmpValue /= i;
            divisionCnt++;
        }

        if (divisionCnt != 0)
        {
            result[i] = divisionCnt;
        }
    }
    if (1 != tmpValue)
    {
        result[tmpValue] = 1;
    }
    return result;
}


int main(void)
{
    long long n;
    cin >> n;

    map<long long, long long> pf;
    pf = PrimeFactorization(n);

    long long tmpN = n;
    long long ans = 0;
    for (const auto& kv : pf) {
        for (long long i = 1; i <= kv.second; i++)
        {
            long long currentZ = pow(kv.first, i);
            if (0 == tmpN%currentZ)
            {
                ans++;
                tmpN /= currentZ;
            }
        }
    }

    cout << ans << endl;
    return 0;
}