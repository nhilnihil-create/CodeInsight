#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
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
    char pm,before;
    ll p=0,m=0;
    ll sum=0;
    while(cin >> pm){
        if(before=='>'&&pm=='<'){
            ll bigger = max(p,m);
            ll smaller = max(min(p,m) -1,(ll)0);
            sum += bigger*(1+bigger)/2 + smaller*(1+smaller)/2;
            p=0;m=0;
        }
        if(pm=='>') m++;
        if(pm=='<') p++;
        before=pm;
    };
    ll bigger = max(p,m);
    ll smaller = max(min(p,m) -1,(ll)0);
    sum += bigger*(1+bigger)/2 + smaller*(1+smaller)/2;
    cout << sum << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    