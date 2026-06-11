#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if((a==b&&c!=a)||(a==c&&a!=b)||(b==c&&a!=b))
    cout<<"Yes";
    else
    cout<<"No";
}
