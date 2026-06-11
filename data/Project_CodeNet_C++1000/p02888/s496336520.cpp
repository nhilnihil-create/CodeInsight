#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+4;
const int mod=1e9+7;
void solve(){
    int n; cin>>n;
    std::vector<int> stick(n);
    for(auto &i:stick)cin>>i;
    sort(stick.begin(),stick.end());
    int ans=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int sum=stick[i]+stick[j];
            int small=upper_bound(stick.begin(),stick.end(),sum-1)-stick.begin();
            ans+=(small-1-j);
        }
    }   
    cout<<ans<<endl;
}   
int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt; 
    tt=1;
    // cin>>tt;
    for(int t=1;t<=tt;t++){
        solve();
    }
} 