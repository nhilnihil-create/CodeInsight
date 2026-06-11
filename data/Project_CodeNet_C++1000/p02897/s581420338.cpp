#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n,cnt=0;
    double m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            cnt++;
        }

    }
     m=cnt/n;
    printf("%.10lf",m);
}