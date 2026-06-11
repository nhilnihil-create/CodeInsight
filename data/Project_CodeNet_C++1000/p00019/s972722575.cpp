#include <iostream>
using namespace std;
long long int f(int n)
{
    long long int m=1;
    for(long long int i=2; i<=n; i++)
        m*=i;
    return m;
}
int main()
{
    long long int a;
    cin>>a;
        cout<<f(a)<<endl;
}