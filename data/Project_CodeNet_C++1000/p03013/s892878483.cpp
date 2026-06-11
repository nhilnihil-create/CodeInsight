#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int INF=1e9;
const int MOD= 1000000007;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),dat(n);
    rep(i,m){
        int b;
        cin>>b;b--;
        a[b]++;
    }
    if(a[0]==0)
        dat[0]++;
    if(a[1]==0){
        if(a[0]==0)
            dat[1]++;
        dat[1]++;
    }
    for(int i=2;i<n;i++){
        if(a[i-2]==0) dat[i]+=dat[i-2];
        if(a[i-1]==0) dat[i]+=dat[i-1];
        dat[i]%=MOD;
    }
    cout<<dat[n-1];
}