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

    vector<ll> ans(n,0);
    rep(i,n){
        if(i%2==0) ans[0]+=a[i];
        else ans[0]-=a[i];
    }

    for(int i=1;i<n;i++){
        ans[i]=2*a[i-1]-ans[i-1];
    }

    rep(i,n) cout<<ans[i]<<" ";
    cout<<endl;
}