#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll int n,d;
    cin>>n>>d;
    ll int count=0;
    while(n--)
    {
        double a,b;
        cin>>a>>b;
        a=a*a;
        b=b*b;
        double m;
        m=sqrt(a+b);
        if(m<=d) count++;
        
    }
    cout<<count;
    return 0;
}
