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
    vector<ll> cnt(100010,0);
    cnt[0]=3;
    ll ans=1;
    rep(i,n){
        cin>>a[i];
        ans=(ans*cnt[a[i]])%MOD;
        cnt[a[i]]--;
        cnt[a[i]+1]++;
    }

    cout<<ans<<endl;
}
