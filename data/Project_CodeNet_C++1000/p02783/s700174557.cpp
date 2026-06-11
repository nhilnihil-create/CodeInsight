#include<iostream>
using namespace std;
int main()
{
    long long h,a,t;
    cin>>h>>a;
    t=h/a;
    if(h%a!=0)
    {
        t++;
    }
    cout<<t<<endl;
    return 0;
}