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
    double a,ans=0;
    rep(i,n){
        cin>>a;
        ans=ans+1/a;
    }
    ans=1/ans;
    cout<<ans<<endl;

    return 0;
}