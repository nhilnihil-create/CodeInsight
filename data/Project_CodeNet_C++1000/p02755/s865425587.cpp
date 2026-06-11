#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    ll a, b,f=1;
    cin>>a>>b;
    for(int i=1;i<=100000;i++)
    if((i*8)/100==a&&i/10==b){cout<<i;f=0;break;}
    if(f)cout<<-1;
}
