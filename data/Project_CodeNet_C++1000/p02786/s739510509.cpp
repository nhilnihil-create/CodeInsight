#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);


long long kill(ll health) {
    if(health==1) {
        return 1;
    }

    return 2*kill(health/2)+1;


}
int main() {
    fast_io;
    ll h;
    cin>>h;

    ll ans;
    ans=kill(h);
    cout<<ans<<endl;
}


