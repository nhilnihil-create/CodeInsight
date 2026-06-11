#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,l,r) for (ll i = (ll)l; i < (ll)(r); i++)

int main(){
    int H,W,A,B;
    cin >> H >> W >> A >> B;

    rep(i,0,H){
        rep(j,0,W){
            if(i < B && j < A) cout << 0 ;
            else if(!(i < B) && !(j < A)) cout << 0 ;
            else if(i < B || j < A) cout << 1 ;
        }
        cout << endl;
    }
}