#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,sum=0,count=0;
    while(cin>>a>>b)
    {
        sum=a+b;
       while(sum>0)
       {
         sum/=10;
            count++;
       }
       cout<<count<<endl;
       count=0;
    }
    return 0;
}

