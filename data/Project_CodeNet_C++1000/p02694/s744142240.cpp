#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main()
{
   ll x;
   cin>>x;
   ll cnt=0;

    for(ll i=100; i<x; )
    {
        i= i+ (i/100);
        cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}
