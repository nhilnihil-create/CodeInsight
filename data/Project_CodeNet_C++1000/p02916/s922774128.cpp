#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int a[n],b[n],c[n],ans=0;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        cin>>b[i];
    }
    rep(i,n-1){
        cin>>c[i];
    }
    rep(i,n){
        ans+=b[a[i]-1];
        if(a[i+1]-1==a[i])ans+=c[a[i]-1];
    }
    cout<<ans<<endl;

    return 0;
}
