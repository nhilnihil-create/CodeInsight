#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <bitset>
using namespace std;

const long int INF = 1000000007;

int main(void)
{
    long long N, K;
    cin >> N >> K;
    vector<int> a(N);
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }

    // 1ループ分
    long long count = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(a[j] > a[i])
            {
                count++;
            }
        }
        
    }
    // printf("in group : %d\n", count);
    
    // effect by before group
    long long before_effect = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i] < a[j])
            {
                before_effect++;
            }
            
        }
        
    }
    
    // printf("effect by before group : %d\n", before_effect);
    
    // calc ans
    long long ans = count * K % INF;
    // printf("ans1 : %d\n", ans);

    long long bc = K * ((K - 1) / 2) % INF;
    if ((K - 1) % 2 == 1)
    {
        bc += (K - 1) / 2 + 1;
    }
    bc %= INF;
    
    ans += bc * before_effect % INF;

    cout << ans % INF << endl;
}