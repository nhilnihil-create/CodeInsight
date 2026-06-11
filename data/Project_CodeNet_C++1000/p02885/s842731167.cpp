#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    b=b*2;
    if(b>=a)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<a-b<<endl;
    }
    return 0;
}
