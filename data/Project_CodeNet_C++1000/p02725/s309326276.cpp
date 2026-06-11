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
    ll k,n; cin>>k>>n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n-1){
        b[i] = a[i+1] - a[i];
    }
    b[n-1] = a[0]+k-a[n-1];
    sort(all(b));
    ll sum=0;
    rep(i,n-1) sum+=b[i];
    cout<<sum<<endl; 
    return 0;
}