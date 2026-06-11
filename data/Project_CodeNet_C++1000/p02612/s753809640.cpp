#include<iostream>
using namespace std;
int main()
{
    int N,p;
    cin>>N;
    if ((N%1000)!=0)
    {
        p=(N%1000);
        cout<<1000-p;
    }
    else
    {
        cout<<"0";
    }
}