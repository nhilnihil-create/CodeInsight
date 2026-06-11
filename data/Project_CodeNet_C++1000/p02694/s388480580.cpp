#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mx = 1000000000000000000;

int main()
{
    ll n;cin>>n;
    ll sum=100,i;
    for(i=1;i<=5000;i++)
    {
        sum+=(sum/100);
        if(sum>=n)break;
    }
    cout<<i<<endl;






}
