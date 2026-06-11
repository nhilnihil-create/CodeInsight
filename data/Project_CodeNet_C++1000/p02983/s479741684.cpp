#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
ll l,r;
cin>>l>>r;
ll ans=2020;
for(ll i=l;(i<r) && (i<l+2020);i++){
for(ll j=i+1;(j<=r) && (j<i+2021);j++){
    ans=min(ans, i*j%2019);
}
}
cout<<ans<<endl;
}
