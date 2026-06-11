#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,total=1,l,s=1,k;
    cin>>n;
    while(n>1)
    {
        n/=2;
        k=2*s;
        total+=k; 
        s=k;
    }
    cout<<total<<endl;
    return 0;   
}