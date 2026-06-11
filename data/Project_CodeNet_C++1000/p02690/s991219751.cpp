/*
      author : Nishikawa
      created: 10.08.2020 13:28:48
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    ll x;
    cin >> x;
    for(int a=1; a<=500; a++){
        ll sa = 1;
        rep(i,5) sa *= a;
        for(int b=-500; b<=500; b++){
            ll sb = 1;
            rep(i,5) sb*=b;
            if(sa - sb == x){
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}