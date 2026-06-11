#include <iostream>

using namespace std;
int n,k;
int main()
{
    //freopen("A.in","r",stdin);
    scanf("%d%d",&n,&k);
    if (k==1) printf("0");
    else printf("%d",n-k);
}
