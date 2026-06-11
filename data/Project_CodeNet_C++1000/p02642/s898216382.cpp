#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define MAX 1000001

void _main(){
    ll n; cin>>n;
    vector<ll> p(MAX,0); 
    set<ll> s;
    rep(i,n) {ll a;cin >> a; p[a]++;s.insert(a);}
    ll out = 0;
    for(auto i:s){
        for(ll j=2;j<MAX;j++){
            if(i*j>=MAX) break;
            p[i*j]++;
        }
    }
    for(auto i:s){
        if(p[i]==1) out++;
    }
    cout << out << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    