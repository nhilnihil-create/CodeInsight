#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
        double t=n;
        cout<<(t/2.0)/t;
    }
    else
    {
        double t=((n+1.0)/2.0)/n;
        cout<<t;
    }
}
