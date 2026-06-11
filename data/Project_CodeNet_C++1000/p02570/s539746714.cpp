#include <iostream>

using namespace std;

int main()
{
    double D,S,T,A;
    cin>>D;
    cin>>S;
    cin>>T;
    A=D/S;
    if(T>=A)
    {
        cout<<"Yes";
    }
    else if(T<A)
    {
        cout<<"No";
    }

    return 0;
}
