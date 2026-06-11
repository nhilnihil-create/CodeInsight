#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int m=a-b;

    if(m>c)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<c-m<<endl;
    }
    exit(0);
}
