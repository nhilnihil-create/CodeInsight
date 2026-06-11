#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=15000007;
const ll MAX=9187201950435737471;
const int N=100005;
const ll INF=1e17;
const long double PI=acos(-1);

ll po(int x){
    if(x==0){
        return 1;
    }
    ll ret=1;
    for(int i=0;i<x;i++){
        ret=(ret%MOD * 10)%MOD;
    }
    return ret;
}
bool a[200];

void solve(int T){
    int x,n;
    cin>>x>>n;
    if(n==0){
        cout<<x;
        return;
    }
    for(int i=0;i<n;i++){
        int r;
        cin>>r;
        a[r]=true;
    }
    int mn=102,ans=102;
    for(int i=0;i<=101;i++){
        if(a[i]==false){
            if(abs(x-i)<mn){
                ans=i;
                mn=abs(x-i);
            }
        }
    }
    cout<<ans<<"\n";
}

int main() {
    fastio
    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
        //if(i<T)cout<<"\n";
    }
    return 0;
}
/*

for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            cout<<i<<" "<<j<<" "<<n-(i*j)<<"\n";
        }
    }
    */
