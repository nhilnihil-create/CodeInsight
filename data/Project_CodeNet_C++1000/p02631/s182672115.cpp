#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0; i < (int)(n); i++)

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n),ans(n);
    rep(i,n)cin>>a[i];
    int s=0;
    rep(i,n)s^=a[i];
    rep(i,n)ans[i]=s^a[i];
    rep(i,n)cout<<ans[i]<<' ';
    cout<<endl;
}