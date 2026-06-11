#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int prime(int n)
{
    for(int i=3;i<=n/2+1;i+=2)
        if(n%i==0)
        {
            return 0;
        }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    if(n==2)
    {
        cout<<n;
        return 0;
    }
    if(n%2==0) n++;
    while(prime(n)==0)
    {
        n+=2;
    }
    cout<<n;
}