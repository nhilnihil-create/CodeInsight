#include <iostream>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main(void)
{
    int64_t N, K;
    cin >> N >> K;
    int64_t p[1000];
    for (int64_t i = 0; i < N; ++i)
    {
        cin >> p[i];
    }

    sort(p, p+N);

    int64_t ans = 0;
    for (int64_t i = 0; i < K; ++i)
    {
        ans += p[i];
    }

    cout << ans;
    
    return 0;
}
