#include<bits/stdc++.h>
using namespace std;
#define ll "%I64d"
const int max1=100010;
//long long a[max1],b[max1];
int main()
{
    // string s1,s2;
    int a,b,x=0,y=0,z=0;
    cin>>a;
    int c[a+5];
    for(int i=0; i<a; i++)
    {
        cin>>c[i];
        if(x>0)
        {
            if(c[i-1]>=c[i])
            {
                y++;
               // cout<<y<<"\n";
                if(z<=y)
                {
                    z=y;
                   // y=0;
                }
            }
            else
            {
                y=0;
            }
        }
        x++;

    }
    cout<<z<<"\n";
}

