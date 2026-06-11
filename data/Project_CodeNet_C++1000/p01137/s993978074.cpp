#include <stdio.h>
#include <vector>

using namespace std;
int solve(int e)
{
    int minsum=10000000;
    for(int z=0;z*z*z<=e;z++)
    {
        for(int y=0,lim=e-z*z*z;y*y<=lim;y++)
        {
            int x=e-y*y-z*z*z;
            if(minsum>x+y+z)
            {
                minsum=x+y+z;
            }
        }
    }
    return minsum;
}
int main(void)
{
    int e;
    while(scanf("%d",&e)==1 && e)
    {
        printf("%d\n",solve(e));
    }
    return 0;
}