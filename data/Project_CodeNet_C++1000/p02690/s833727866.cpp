#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,l,r) for (ll i = (ll)l; i < (ll)(r); i++)

int main(){
    ll X; cin >> X;
    ll A = -999,B = -999;
    for(int a = -200; a<=200; a++){
        for(int b = -200; b<=200; b++){
            if(pow(a,5) - pow(b,5) == X){
                A = a; B = b;
            }
        }
    }
    cout << A << " " << B << endl;
}