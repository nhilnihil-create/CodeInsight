#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,t,c;
    cin>>n>>x>>t;
    c=n/x;
    if(n%x)
    {
        c++;
    }
    cout<<c*t;
}

