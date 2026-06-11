#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<int> w(n);
    vector<int> sum(n);
    rep(i,n){
        cin>>w[i];
        if(i==0) sum[i]=w[i];
        else sum[i]=sum[i-1]+w[i];
    }
    int ans=sum[n-1];
    rep(i,n-1){
        ans=min(ans,std::abs(sum[n-1]-sum[i]-sum[i]));
    }
    cout<<ans<<endl;
}