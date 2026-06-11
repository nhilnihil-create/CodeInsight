#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second

void solve(){
    int k,n; cin>>k>>n;
    vector<int> v(k);
    for(int i=0;i<k;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++) ans+=v[i];
    cout<<ans;
}
int main() {
    // int t; cin>>t;
    // while(t--){
        solve();
        // cout<<endl;
    // }
}