#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int z=(a+b)/2;
    double z1=(double)(a+b)/2;
    if(z1-z==0)
        cout<<z<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;

    return 0;
}
