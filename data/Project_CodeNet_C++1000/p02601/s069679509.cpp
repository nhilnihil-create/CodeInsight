#include <iostream>

using namespace std;

int main()
{
    int a,b,c,k,cont;
    cin>>a>>b>>c>>k;
    while(a>=b)
    {
        cont++;
        b=b*2;
    }
    while(b>=c)
    {
        cont++;
        c=c*2;
    }
    if(cont>k)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
}