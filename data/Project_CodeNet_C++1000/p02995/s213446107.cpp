#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    ll a,b,c,d;cin >>a>>b>>c>>d;
    ll g=__gcd(c,d);
    ll lcm=c*d/g;
    a--;
    ll ctc=b/c-a/c;
    ll ctd=b/d-a/d;
    ll ctl=b/lcm-a/lcm;
    ll U=b-a;
    ll ans=U-(ctc+ctd-ctl);
    cout <<ans <<endl;
}

