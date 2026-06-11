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
    ll a,b,c,k; cin >> a >> b >> c >> k;
    if(k <= a) cout << k << endl;
    else if(k <= a + b) cout << a << endl;
    else cout << a-(k-a-b) << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    