#include <cstdio>
#include <algorithm>
#include <cmath>

int d[1005];

int main()
{
    int n;
    while(scanf("%d ", &n) && n > 0)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d ", &d[i]);
        }

        int min = 1 << 30;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == j)
                {
                    continue;
                }
                else
                {
                    min = std::min(min, std::abs(d[i] - d[j]));
                }
            }
        }
        printf("%d\n", min);
    }
    return 0;
}
