//written_by: Poushi
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
   long long int n,k,i;
   scanf("%lld", &n);
   long long int ara[n], taka, yen=1000;
   for(i=0; i<n; i++)
    scanf("%lld", &ara[i]);
    for(i=0;i<n-1;i++)
    {
        if(ara[i]<ara[i+1])
        {
            taka=yen/ara[i];
            yen-=(taka*ara[i]);
            yen+=(taka*ara[i+1]);
        }
    }
    printf("%lld\n", yen);
}
