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
    vector<ll> a(n);
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum^=a[i];
    }

    rep(i,n){
        ll ans=sum^a[i];
        cout<<ans<<" ";
    }
    cout<<endl;
}

