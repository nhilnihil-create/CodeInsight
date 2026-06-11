#include "bits/stdc++.h"
#define rep(i,n) for (ll i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,m;
    cin >> n >> m;
    if(n%2!=0){
        rep(i,m){
            cout << n/2-i << " " << n/2+i+1 << endl;
        }
    }
    else{
        rep(i,m){
            if(i*2<=m-1){
            cout << n/2-i << " " << n/2+i+1 << endl;
            }
            else{
            cout << n/2-i-1 << " " << n/2+i+1 << endl;
                
            }
        }
    }
    

    return 0;
}