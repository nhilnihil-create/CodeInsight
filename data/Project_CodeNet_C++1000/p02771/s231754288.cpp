#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b&&a!=c&&b!=c||c==b&&c!=a&&b!=a||a==c&&b!=c&&b!=a)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}