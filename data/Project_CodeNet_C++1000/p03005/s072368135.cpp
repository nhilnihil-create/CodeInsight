#include<iostream>
using namespace std;
int main()
{
    int n,k,d;
    cin>>n>>k;
    if(k<=1)
    {
        cout<<"0"<<endl;
    }
    else
    {
        d=n-k;
        cout<<d<<endl;
    }
    return 0;
}
