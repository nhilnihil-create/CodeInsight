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
    ll a,b,n; cin >> a >> b >> n;
    auto func = [&](ll x){
        return (a*x)/b;
    };
    ll out;
    if(b<=n) out = func(b-1);
    else out = func(n);

    cout << out << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    