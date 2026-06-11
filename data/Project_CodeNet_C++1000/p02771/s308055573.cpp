#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b||b==c||c==a)
        if(a==b&&b==c&&c==a)
            cout<<"No";
        else   
            cout<<"Yes";
    else
        cout<<"No";
}