#include<iostream>
using namespace std;
int main()
{
    long long n,k,s=0;
    cin>>n>>k;
    while(n!=0)
    {
        n/=k;
        s++;
    }
    cout<<s<<endl;
    return 0;
}