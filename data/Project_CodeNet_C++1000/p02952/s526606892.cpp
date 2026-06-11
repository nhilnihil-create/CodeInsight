#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n,cnt=0; cin>>n;
    REP(i,1,10) if(i<=n) cnt++;
    REP(i,100,1000) if(i<=n) cnt++;
    REP(i,10000,1e5) if(i<=n) cnt++;
    cout<<cnt<<endl;
    return 0;
}