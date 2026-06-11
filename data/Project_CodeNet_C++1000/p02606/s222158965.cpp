#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,i,count=0;
    cin>>a>>b>>c;
    for(i=1; ; i++)
    {
        if(i*c>=a)
        {
            count++;
            if(i*c>b)
                break;
        }
    }
    cout<<count-1;
    return 0;
}
