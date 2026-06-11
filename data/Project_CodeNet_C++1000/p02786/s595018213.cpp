#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vl vector
using namespace std;
int main()
{
    ll n,m,a=0,i,j;
    cin>>n;
    ll count=0;
    ll no=1;
    while(1)
    {
        count+=no;
        n/=2;
        no*=2;
        if(n==0) break;
    }
    cout<<count;
}