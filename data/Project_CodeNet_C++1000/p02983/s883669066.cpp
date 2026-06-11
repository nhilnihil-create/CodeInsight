#include <cstdio>
#include <stdlib.h>
#include <algorithm>



int main()
{
    int l, r;
    scanf("%d%d", &l, &r);
    if(r-l >= 2019)
        printf("0\n");
    else
    {
        long long  minv = 3e9;
        for(int i=l; i < r; i++)
            for(int j=i+1; j <=r; j++)
                minv = std::min((long long)((i%2019)*(j%2019))%2019, minv);
        printf("%lld\n", minv);
    }


    return 0;
}
