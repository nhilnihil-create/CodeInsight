#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    if( n%2 == 1)
    {
        cout<<0<<endl;
    } else
    {
       ll ans =0;
       ll curr = 10;
       while( n/curr )
       {
           ans += ( n/curr);
           curr = curr * 5;
       }
       cout<<ans;
    }
}