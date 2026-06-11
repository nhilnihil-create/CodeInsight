#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,k;
    cin>>a>>b>>k;
    a=a-k;
    if(a<=0)
    {
        b=b+a;
        a=0;
    }
    if(b<=0)
    {
        b=0;
    }
    cout<<a<<" "<<b<<endl;


return 0;}
