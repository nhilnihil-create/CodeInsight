#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a<b || b==1)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<a-b<<endl;
    }
    return 0;
}
