#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define beg begin()
#define end end()


void _main(){
    ll n ; cin >> n;
    vector<ll> backet(n+1,0);
    vector<ll> as;
    ll sumc = 0;
    rep(i,n){
        ll a ; cin >> a;
        as.push_back(a);
        backet[a]++;
    }
    rep(i,n+1){
        if(backet[i]>0) sumc+=(backet[i]*(backet[i]-1))/2;
    }
    for(auto i : as){
        ll before = backet[i];
        ll after = before-1;
        ll out = sumc;
        if(before>0) {
            out -= (before*(before-1))/2 ;
            if(after>0){
                out += (after*(after-1))/2;
            }
        }
        cout << out << endl;
    }
    
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    