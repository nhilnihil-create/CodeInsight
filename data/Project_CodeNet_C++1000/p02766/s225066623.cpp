#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main()
{
    long long int n,k,i=1;
    cin>>n>>k;
    if(n==k)
    {
        cout<<"2";
        return 0;
    }
    if(n<k)
    {
        cout<<"1";
        return 0;
    }
    while(n>pow(k,i))
    {
        i++;
        if(n<pow(k,i))
        {
            cout<<i;
            return 0;
        }
        if(n==pow(k,i))
        {
            cout<<i+1;
            return 0;
        }
    }
}