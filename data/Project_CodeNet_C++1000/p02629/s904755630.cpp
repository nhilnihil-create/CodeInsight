#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[5000000];
int main()
{
    ll n;
    ll c=1;
    int m=0;
    cin>>n;
    while(n>0)
    {
        ll k=n%(26);
        if(k==0)
        {
            k=26;
            a[m++]='z';
        }
        else
        {
            a[m++]='a'+k-1;
        }
        n=(n-k)/26;

    }
    for(int i=m-1;i>=0;i--)
    {
        cout<<a[i];
    }
}