#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll H;cin>>H;
    ll ans=0;
    ll x=1;
    while(H>0){
        ans+=x;
        H/=2;
        x*=2;
    }
    cout<<ans<<endl;
}