#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e;
    cin>>a>>b>>c;
    d=a-b;
    if(d<c)
    {
       e=c-d;
       cout<<e<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }
}
