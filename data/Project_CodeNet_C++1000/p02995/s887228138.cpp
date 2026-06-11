#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;
    auto f=[](ll i,ll t){
        return i/t;
    };
    auto solve=[&](ll s){
        return f(s,c)+f(s,d)-f(s,lcm(c,d));
    };
    cout<<(b-a)-(solve(b)-solve(a));
}