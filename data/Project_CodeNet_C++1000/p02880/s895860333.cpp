#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,m=1;
    cin>>n;
    for(i=1;i<=9;i++)
    {
        if(!(n%i)&&(n/i>=1&&n/i<=9))
        {
            puts("Yes");
            m=0;
            break;

        }
    }
    if(m)
        puts("No");
    return 0;
}
