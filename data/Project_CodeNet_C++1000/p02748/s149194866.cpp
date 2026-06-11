#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll A,B,m;
    cin>>A>>B>>m;

    vector<ll> a(A),b(B);
    rep(i,A) cin>>a[i];
    rep(i,B) cin>>b[i];
    
    ll minv= *min_element(a.begin(),a.end())+ *min_element(b.begin(),b.end());
    rep(i,m){
        ll x,y,c;
        cin>>x>>y>>c;
        ll sum;
        sum=a[x-1]+b[y-1]-c;
        minv=min(minv,sum);
    }
    cout<<minv<<"\n";
    return 0;
}