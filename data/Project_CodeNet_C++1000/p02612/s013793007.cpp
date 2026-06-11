#include<bits/stdc++.h>
using namespace std;
int main()
{

    long int a,b=0,sum=0;
    cin>>a;
    b=(a%1000);
    if(a%1000!=0)
    {
        sum=1000-b;
        cout<<sum<<endl;
    }

    else
    {
        cout<<0<<endl;
    }
    return 0;

}

