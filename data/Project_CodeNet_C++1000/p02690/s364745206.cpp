#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long x,a,b,l=0;
    cin>>x;
    for(b=-1000;b<=1000;b++)
    {
        for(a=0;a<=1000;a++)
        {
            if(((a*a*a*a*a)-(b*b*b*b*b))==x)
            {
                l++;
               cout<<a<<" "<<b<<endl;
                break;
            }
        }
        if(l>0)
        {
            break;
        }
    }
    return 0;
}