#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <bitset>
#include <string>
#include <cstdio>
#include <math.h>
using namespace std;

const long long int INF = 1000000007;

int main(void)
{
    long long N;
    cin >> N;

    if (N % 2 == 0)
    {
        long long ans = 0;
        for (long long i = 5; i <= N; i*=5)
        {
            ans += N / (i * 2);
        }
        
        cout << ans << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}