#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int ans=0;
    rep(i,n){
        a[i]--;
        if(ans==a[i]){
            ans++;
        }
    }
    if(ans==0){
    cout<<"-1"<<endl;
    return 0;
    }
    cout<<n-ans<<endl;
}