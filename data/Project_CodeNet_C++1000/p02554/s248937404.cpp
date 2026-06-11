#include "bits/stdc++.h"
using namespace std;

#define int long long 
const int mod=1e9+7;

int bm(int x,int y){
    if(y==0)return 1;
    if(y==1)return x;
    if(y&1)return (x*bm(x,y-1))%mod;
    int f=bm(x,y/2);
    return (f*f)%mod;
}
signed  main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long ans=((bm(10,n)+bm(8,n)))%mod;
    ans=(ans-(bm(9,n)*2)+mod+mod)%mod;
    cout<<ans%mod<<endl;

}


