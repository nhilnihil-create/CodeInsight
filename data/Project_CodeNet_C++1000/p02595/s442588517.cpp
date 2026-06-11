#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    ll n,d;
    cin>>n>>d;
    vector<ll> x(n),y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];
    int ans = 0;
    ll dd = d*d;
    for(int i=0; i<n; i++){
        ll tmp = powl(x[i],2)+powl(y[i],2);
        if(tmp<=dd){
            ans++;
        }
    }
    cout<<ans<<endl;
}
