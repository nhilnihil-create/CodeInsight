#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    vector<ll> p(n+1), q(n+1);
    rep(i,n+1) cin>>p[i];
    q[n]=p[n];
    rep(i,n) q[n-i-1]=q[n-i]+p[n-i-1];
    vector<ll> an(n+1);
    an[0]=1;
    if(p[0]==1){
        if(n==0){
            cout<<1<<endl;
            return 0;
        }
        else{
            cout<<-1<<endl;
            return 0;
        }
    }
    else if(p[0]>1){
        cout<<-1<<endl;
        return 0;
    }
    rep(i,n){
        ll a=an[i]-p[i];
        if(a<=0){
            if(i<n){
                cout<<-1<<endl;
                return 0;
            }
        }
        else{
            an[i+1]=min(a*2,q[i+1]);
        }
    }
    if(an[n]!=p[n]){
        cout<<-1<<endl;
        return 0;
    }
    ll ans=0;
    rep(i,n+1) ans+=an[i];
    cout<<ans<<endl;
    return 0;
}
