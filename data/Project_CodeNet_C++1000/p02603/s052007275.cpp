
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    ll ans=1000;
    ll kabu=0;
    rep(i,n-1){
        if(a[i]<a[i+1]){
            kabu=ans/a[i];
            ans=ans%a[i];
            ans+=kabu*a[i+1];
        }
//        cout<<ans<<" "<<kabu<<endl;
    }
//    ans+=kabu*a[n-1];
    cout<<ans<<endl;
    return 0;
}
