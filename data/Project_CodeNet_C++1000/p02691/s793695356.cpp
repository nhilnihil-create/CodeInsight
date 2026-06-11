#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n;
    cin>>n;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    vector<ll> r(2e5+70),l(2e5+7,0);
    rep(i,n){
        if(i+p[i]>=0 && i+p[i]<2e5+5){
            r[i+p[i]]++;
        }
        if(i-p[i]>=0 && i-p[i]<2e5+5){
            l[i-p[i]]++;
        }
    }
    ll ans=0;
    rep(i,2e5){
        ans+=r[i]*l[i];
    }
    cout<<ans<<endl;
    return 0;
}
