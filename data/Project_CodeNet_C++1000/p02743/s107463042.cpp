#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll a,b,c;cin >>a>>b>>c;
    bool flg=true;
    ll d=c-a-b;if(d<0)flg=false;
    if(4*a*b>=d*d)flg=false;
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}
