#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int h,w,a,b,c;
    cin>>h>>w;
    a=h*w;
    if(h==1 || w==1)
    {
        cout<<1<<endl;
        return 0;
    }
    if(h%2==0)
    {
        b=h/2;
        c=w*b;
        cout<<a-c<<endl;
    }
    else
    {
        b=h/2;
        c=b*w+w/2;
        cout<<a-c<<endl;
    }
}
