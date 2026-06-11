#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    ll b[n+1];
    b[0]=0;
    for(int i=0;i<n;i++){
        b[i+1]=(b[i]+a[i])%k;
    }
    map<ll,ll> mp;
    ll ans=0;
    queue<ll> q;
    for(int i=0;i<=n;i++){
        ans+=mp[b[i]];
        mp[b[i]]++;
        q.push(b[i]);
        if((q.size())==k){
            mp[q.front()]--;
            q.pop();
        }
    }
    cout << ans<<endl;
    return 0;
}
