#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    ll a,b,c,k;

    cin>>a>>b>>c>>k;

    ll ans=0;
    while(k>0) {
        while(k>0&&a>0) {
            ans+=1;
            a--;
            k--;
        }
        while(k>0&&b>0) {
            k--;
            b--;
        }
        while(k>0&&c>0) {
            k--;
            ans-=1;
            c--;
        }
    }
    cout<<ans<<endl;

}


