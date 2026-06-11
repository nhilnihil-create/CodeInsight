#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    ll a,b,c,k;

    cin>>a>>b>>c>>k;

    ll ans=0;
    if(k<=a) {
        ans+=k;
        cout<<ans<<endl;
        return 0;
    }
    else {
        k-=a;
        ans+=a;
    }

    if(k<=b) {
        cout<<ans<<endl;
        return 0;
    }
    else {
        k-=b;
    }

    if(k<=c) {
        ans-=k;
        cout<<ans<<endl;
        return 0;
    }

}


