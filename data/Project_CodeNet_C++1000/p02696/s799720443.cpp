#include<iostream>
using namespace std;
int main()
{
    long long a,b,n;
    cin>>a>>b>>n;
    if(b>n)
    {
        cout<<((a*n)/b)<<endl;
    }
    else
    {
        cout<<((a*(b-1))/b)<<endl;
    }
    return 0;
}