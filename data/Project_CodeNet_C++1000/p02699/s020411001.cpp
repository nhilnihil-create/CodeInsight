///c. sheep and wolves
#include <stdio.h>
#include <math.h>

int main()
{
    int s,w;
    scanf("%d %d",&s, &w);
    if(w>=s) printf("unsafe");
    else printf("safe");
    
    return 0;
}