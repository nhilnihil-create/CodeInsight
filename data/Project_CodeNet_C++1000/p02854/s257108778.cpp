#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    ll sum=0,sum2=0,ans=1e18;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    rep(i,n){
        sum-=a[i];
        sum2+=a[i];
        ans=min(ans,abs(sum-sum2));
    }
    cout<<ans<<endl;
}