#include<iostream>
using namespace std;
int main()
{
    int a1,a2,a3,a;

    cin>>a1>>a2>>a3;

    if(a1>0&&a1<14&&a2>0&&a2<14&&a3>0&&a3<14)
    {
        a=a1+a2+a3;
        if(a<22)
            cout<<"win"<<endl;
        else
            cout<<"bust"<<endl;
    }

    return 0;
}
