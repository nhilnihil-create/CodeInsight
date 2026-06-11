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
    ll m,d,cnt=0; cin>>m>>d;
    rep(i,m)rep(j,d){
        ll a=(j+1)%10,b=(j+1)/10;
        if(a>=2 && b>=2 && a*b==i+1) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}