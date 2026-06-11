#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    rep(i,n+1) cin>>a[i];

    if(n==0){
        if(a[0]==1) cout<<1<<endl;
        else cout<<-1<<endl;
        return 0;
    }

    if(a[0]!=0){
        cout<<-1<<endl;
        return 0;
    }

    ll cur=1;
    ll ans=1;
    ll tot=0;
    rep(i,n+1) tot+=a[i];
    for(int i=1;i<n+1;i++){
        cur*=2;
        if(cur<a[i]){
            cout<<-1<<endl;
            return 0;
        }

        ans+=min(cur,tot);
        cur=min(cur,tot)-a[i];
        tot-=a[i];
    }
    
    cout<<ans<<endl;
}