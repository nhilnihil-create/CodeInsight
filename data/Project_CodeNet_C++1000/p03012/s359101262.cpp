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
    int w[n];
    rep(i,n){
        cin>>w[i];
    }
    int ans=1e9;
    rep(i,n){
        int sum=0;
        rep(j,n){
            if(j<i){
                sum+=w[j];
            }
            else{
                sum-=w[j];
            }
        }
        ans=min(ans,abs(sum));
    }
    cout<<ans<<endl;


    return 0;
}