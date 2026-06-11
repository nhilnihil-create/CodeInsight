#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
const int N=1e6;
ll v[N+10];
int main()
{
     ll n;

     cin>>n;

     if(n%1000==0)cout<<0<<endl;
     else
    cout<<1000-(n%1000)<<endl;
}

