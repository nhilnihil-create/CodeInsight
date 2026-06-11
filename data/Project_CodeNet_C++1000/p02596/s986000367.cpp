/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    ll n;
    cin>>n;
    ll x=7;
    ll flag=0;
    for(ll i=1;i<=n;i++)
    {
        if(x%n==0) {cout<<i<<endl; flag=1; break;}
        else x=((x*10)+7)%n;
    }
    if(flag==0) cout<<-1<<endl;
    return 0;
}
