#include<iostream>
using namespace std;
int main()
{
    long long n,l,m,k;
    cin>>n;
    l=n/500;
    m=n%500;
    k=m/5;
    cout<<((l*1000)+(k*5))<<endl;
    return 0;
}