#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<long long, long long>> prime_factorize(ll num)
{
    vector<pair<long long, long long> > res;
    for(ll i=2;i*i<=num;i++){
        if(num%i!=0)continue;
        ll ex=0;
        while(num%i==0){
            ex++;
            num/=i;
        }
        res.push_back(make_pair(i, ex));
    }
    if (num!=1) res.push_back(make_pair(num, 1));
    return res;
}

int main()
{
    ll N;
    cin >> N;
    auto pf=prime_factorize(N);
    ll res=0;
    for(auto p:pf){
        ll e=p.second;
        ll max=0;
        ll x=1;
        while(e>=x)e-=x++,++max;
        res+=max;
    }    
    cout<<res;
    return 0;
}