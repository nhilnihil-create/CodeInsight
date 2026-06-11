#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a<b)
        cout<<"0"<<endl;
    else
    {
        b=b*2;
        if(a>b)
            cout<<a-b<<endl;
        else
            cout<<"0"<<endl;
    }
}
