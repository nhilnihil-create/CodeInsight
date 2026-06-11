#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,m,v,p; cin>>n>>m>>v>>p;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(),a.end(),greater<ll>());
    vector<ll> tmp={};
    ll tmp_sum=0;
    ll res=p;
    for(ll i=p; i<n; i++){
        tmp.push_back(a[i-1]);
        tmp_sum+=a[i-1];
        if(i-p+1<=n-v){
            if(a[p-1]-a[i]<=m) res++;
        }else{
            ll thre=a[i]+m;
            ll add=v-n+i-p+1;
            if(tmp[0]>thre) break;
            ll sum=thre*tmp.size()-tmp_sum;
            if(sum>=add*m) res++;
            else break;
        }
    }
    cout<<res<<endl;
    return 0;
}