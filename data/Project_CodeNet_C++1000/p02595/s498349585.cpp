#include<bits/stdc++.h>
using namespace std;
int main()
{
    long double a,r,b,x,y;
    long long int c=0;
    cin>>a>>b;
    while(a--)
    {
        cin>>x>>y;
        r=sqrt(x*x+y*y);
        if(r<=b)
            c++;
    }
    cout<<c<<endl;
    return 0;
}
