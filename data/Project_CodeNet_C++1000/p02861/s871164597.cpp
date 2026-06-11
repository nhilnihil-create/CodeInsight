#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)
ll kaijou(ll n)
{
    if(n==1) return 1;
    else return n*kaijou(n-1);
}

int main()
{
    ll n;
    double ans=0;
    cin>>n;
    vector<double> x(n),y(n);
    vector<ll> data(n);
    rep(i,n) cin>>x[i]>>y[i];
    rep(i,n) data[i]=i;
    auto solve=[&](int a,int b)
    {
        double xdef=x[a]-x[b];
        double ydef=y[a]-y[b];
        return sqrt(xdef*xdef+ydef*ydef);
    };
    do{
        rep(i,n-1)
        {
            ans+=solve(data[i],data[i+1]);
        }
    }while(next_permutation(data.begin(),data.end()));
    ans/=kaijou(n);
    printf("%.10f",ans);
}