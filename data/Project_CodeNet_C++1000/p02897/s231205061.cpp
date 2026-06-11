#include <iostream>

using namespace std;

int main()
{
    double n;
    int np;
    cin>>n;
    np=n;
    if(np%2==0)
    {
        cout<<(n/2)/n;
    }
    else
    {
        cout<<((n+1)/2)/n;
    }
}