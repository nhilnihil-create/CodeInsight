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
    ll n; cin>>n;
    vector<ll> b(n-1),a(n);
    rep(i,n-1)cin>>b[i];
    a[0]=b[0],a[n-1]=b[n-2];
    for(int i=1;i<n-1;i++){
        a[i] = min(b[i-1],b[i]);
    }
    ll sum=accumulate(all(a),0);
    cout<<sum<<endl;
    return 0;
}