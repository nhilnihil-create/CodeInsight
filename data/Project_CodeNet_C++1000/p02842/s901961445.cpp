#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int a,b;
    int n,temp;
    cin >> n;
    a = n/1.08;
    //printf("%d",a);
    b = (a+1)*1.08;
    //printf("%d",b);
    if(a*1.08==n)
    {
        printf("%d",a);
    }
    else if( b==n)
    {
         printf("%d",a+1);
    }
    else
    {
        printf(":(");
    }
}
