#include <iostream>
using namespace std;

typedef long long ll;
const ll N=1e9;
int n,m;
ll sum;

int main()
{
    scanf("%d%d%lld",&n,&m,&sum);
    int f=0,flag=0;
    while(f<n)
    {
        if(f<m)
        {
            printf("%lld ",sum);
        }
        else
        {
            if(sum!=N)
                printf("%lld ",sum+1);
            else
                printf("%lld ",sum-1);
        }
        f++;
    }
    printf("\n");
    return 0;
}