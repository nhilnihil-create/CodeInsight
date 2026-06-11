#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int c=(a+b)/2;
    if(c*2==(a+b))
    cout<<c;
    else
        cout<<"IMPOSSIBLE"<<endl;

    return 0;
}