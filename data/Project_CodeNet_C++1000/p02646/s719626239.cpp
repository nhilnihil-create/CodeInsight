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
    ll a,v,b,w,t; 
    cin >> a >> v >> b >> w >> t ;
    if(abs(a-b) <= (v-w)*t) cout << "YES"<<endl;
    else cout << "NO"  << endl;

    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    