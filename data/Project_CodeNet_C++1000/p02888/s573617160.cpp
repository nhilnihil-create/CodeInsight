#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF (INT_MAX)
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){
    int n,ans=0;
    cin>>n;
    vector<int> dat(n);
    rep(i,n) cin>>dat[i];
    sort(dat.begin(),dat.end());
    rep(i,n){
        for(int j=i+1;j<n;j++){
            int r=lower_bound(dat.begin(),dat.end(),dat[i]+dat[j])-dat.begin();
            int l=j+1;
            ans+=r-l;
        }
    }
    cout<<ans<<endl;
}