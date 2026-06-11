#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long ;
int main()
{
    ll h;
    cin>>h;
    ll ans=1,i=1;
    while(h!=1){
        i*=2;
        h/=2;
        ans+=i;
    }
    cout<<ans;
}