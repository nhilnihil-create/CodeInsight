#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i;
    cin>>n>>k;
    for(i=-(n-1);i<= n-1;i++)
    {
        printf("%d ",k-(-i));
    }
    return 0;
}
