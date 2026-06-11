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
    int d[n];
    rep(i,n){
        cin>>d[i];
    }
    int ans=0;
    rep(i,n){
        for(int j=i;j<n;j++){
            ans=ans+d[i]*d[j];
        }
    }
    rep(i,n){
        ans=ans-d[i]*d[i];
    }
    cout<<ans<<endl;

    return 0;
}