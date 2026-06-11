#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,x = 1000,y;
    cin>>n;
    while(n>x)
    {
        x+=1000;
    }
    if(x==n)
        cout<<0<<endl;
    else
    {
    y = x - n;
     cout<<y<<endl;
    }
    return 0;
}
