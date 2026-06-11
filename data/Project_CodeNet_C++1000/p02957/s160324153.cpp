#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    long long a,b;
    cin>>a>>b;

    if((a*a - b*b)% (2*a - 2*b) == 0)
    {
        ll k = (a*a - b*b)/(2*a - 2*b);
        cout<<k<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }



}
