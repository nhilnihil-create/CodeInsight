#include<iostream>
using namespace std;
int main()
{
    int a,b,c,n;
    cin>>a>>b>>c;
    n=a+b+c;
    if(n<22)
        cout<<"win"<<endl;
    else
        cout<<"bust"<<endl;
    return 0;
}
