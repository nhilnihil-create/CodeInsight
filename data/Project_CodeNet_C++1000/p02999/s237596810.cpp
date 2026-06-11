#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a>=0 && a<=9 && b>=0 && b<=9)
    {
        if(a>=b)
            cout<< "10"<<endl;
        else
            cout<< "0"<<endl;
    }
    return 0;
}
