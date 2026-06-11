#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second

void solve(){
    ll n; cin>>n;
    string ans="";
    while(n){
        int rem = n%26;
        if(rem==0){
            ans += rem + 'z';
            n = (n/26) - 1;
        }else{
            ans += (rem-1) + 'a';
            n /= 26;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
int main() {
    // int t; cin>>t;
    // while(t--){
        solve();
        // cout<<endl;
    // }
}