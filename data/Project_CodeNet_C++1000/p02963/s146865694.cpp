#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll s;
    cin >> s;
    ll x,y,z,w;
    x=1000000000;
    w=s/x;
    ++w;
    ll sa;
    sa=w*x-s;
    y=sa;
    z=1;

    if(s==1000000000000000000){
        z=0;
        y=0;
        w=x;
    }
    


    cout << 0 << endl;
    cout << 0 << endl;
    cout << x << endl;
    cout << z << endl;
    cout << y << endl;
    cout << w << endl;
    

    return 0;
}