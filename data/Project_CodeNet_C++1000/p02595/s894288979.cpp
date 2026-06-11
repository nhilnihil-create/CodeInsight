#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    double n,d;
    cin>>n>>d;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        double x,y;
        cin>>x>>y;
        if(sqrt(x*x+y*y)<=d) ans++;
    }
    cout<<ans;
    return 0;
}
