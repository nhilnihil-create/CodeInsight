#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int n; cin>>n;
    vector<ll> a;
    rep(i,n){
        ll b; cin>>b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    ll ans=0;
    if(n%2==0){
        rep(i,n/2){
            ans+=a[i]*2;
        }
        ans-=a[0];
    }
    else{
        rep(i,n/2+1){
            ans+=a[i]*2;
        }
        ans-=(a[0]+a[n/2]);
    }
    cout<<ans<<endl;
}