#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
#define PI 3.1415926535897932384626433832795028841971693993
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> dat(1e7);
    dat[1]=7%n;
    for(int i=2;i<=n;i++){
        dat[i]=(dat[i-1]*10+7)%n;
    }
    rep(i,n){
        if(dat[i]==0){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}