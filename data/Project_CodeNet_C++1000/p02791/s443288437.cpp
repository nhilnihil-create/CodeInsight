#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,cnt=1;
    cin>>n;
    vector<ll> p(n);
    rep(i,n) cin>>p[i];
    ll mini=p[0];
    rep(i,n){
        if(mini>p[i]){
            mini = min(mini,p[i]);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}