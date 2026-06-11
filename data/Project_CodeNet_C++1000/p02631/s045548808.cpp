#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    ll x_or=0;
    for(int i=0;i<n;++i){
        cin>>v[i];
        x_or ^= v[i];
    }
    for(int i=0;i<n;i++){
        cout<<(v[i]^x_or)<<" ";
    }
}
int main() {
    // int t; cin>>t;
    // while(t--){
        solve();
        // cout<<endl;
    // }
}