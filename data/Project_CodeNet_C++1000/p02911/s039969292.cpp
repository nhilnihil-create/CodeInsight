#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(q);
    rep(i,q) cin>>a[i];

    if(k>q){
        rep(i,n) cout<<"Yes"<<"\n";
        return 0;
    }
    else{
        //vector<ll> cnt(n+1,0);
        map<int,int> cnt;
        rep(i,q) cnt[a[i]]++;
        for(int i=1;i<=n;i++){
            if(cnt[i]>=q-k+1) cout<<"Yes"<<"\n";
            else cout<<"No"<<"\n";
        }
        return 0;
    }
}