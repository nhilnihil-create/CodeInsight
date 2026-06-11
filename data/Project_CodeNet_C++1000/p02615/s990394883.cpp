#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    reverse(all(a));
    ll ans=a[0];
    int cnt=0,id=1;
    rep(i,n-2){
        if(cnt==0){
            cnt++;
            ans+=a[id];
        }
        else{
            ans+=a[id];
            cnt=0;
            id++;
        }
    }

    cout<<ans<<endl;
}