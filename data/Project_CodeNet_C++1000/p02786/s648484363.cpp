#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    ll h;
    cin>>h;
    ll cnt=0;
    ll ans=1;
    while(h!=1){
        h/=2;
        cnt++;
        ans+=pow(2,cnt);
    }
    cout<<ans<<endl;
}