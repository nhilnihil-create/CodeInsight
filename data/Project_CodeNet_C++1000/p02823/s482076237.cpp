#include <algorithm>
#include <iostream> //標準入出力
#include <fstream>  //ファイルでの入出力
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <utility> //pair
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define MOD 1000000007
#define pair(a) pair<a,a>

void _main(){
    ll n,a,b; cin >> n>>a>>b;
    ll out;
    if((b-a)%2==0) out = (b-a)/2;
    else {
        ll tillw;
        if(b-1 > n-a) tillw = n-b;
        else tillw = a-1;
        out = tillw+1+(b-a-1)/2;
    }
    
    cout << out <<endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}