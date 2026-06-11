#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll l,r,d; cin>>l>>r>>d;
    ll cnt=0;
    for(int i=l; i<=r; i++) cnt+=i%d==0;
    cout<<cnt<<endl;
    return 0;
}