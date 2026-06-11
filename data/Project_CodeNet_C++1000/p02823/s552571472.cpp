#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    ll n,a,b; cin>>n>>a>>b;
    if((a-b)%2==0){
        cout<<abs(a-b)/2<<endl;
        return 0;
    }
    ll ans=a+b-2; ans=(ans+1)/2;
    ll c=2*n-a-b; c=(c+1)/2;
    ans=min(ans,c);
    cout<<ans<<endl;
    return 0;
}