#include <iostream>
using namespace std;

int main()
{
    long long int n,a,b;
    cin>>n>>a>>b;
    long long int rem;
    long long int count;
    count=n/(a+b);
    count=count*a;
    
    rem=n%(a+b);
    if(rem<a)
    count=count+rem;
    else
    count=count+a;
    
    cout<<count;
    
    return 0;
}