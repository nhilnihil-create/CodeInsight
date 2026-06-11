#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

ll zyo(ll x){
    int z=x;
    rep(i,4){
        x *=z;
    }
    return x;
}

int main(){
    ll X; cin >> X;
    ll ue = 1e9;
    
    for(int i=0; i<ue; i++){
        //cout << i << " ";
        for(int j=0; j<i; j++){
            //cout << zyo(i) << "-" << zyo(j) << endl;
            if(zyo(i) - zyo(j) == X){
                cout << i <<" "<< j << endl;
                return 0;
            }else if(zyo(i) - zyo(-j) == X){
                cout << i << " " << -j << endl;
                return 0;
            }
        }
    }
}
