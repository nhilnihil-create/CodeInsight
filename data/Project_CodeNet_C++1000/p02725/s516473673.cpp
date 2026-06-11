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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define MAX 1000000007
#define pair(a) pair<a,a>

void _main(){
    ll ma = 0;
    ll k,n; cin >> k >> n;
    ll a0,a1,a2;cin >> a0;
    a1=a0;
    rep(i,n-1){
        cin >> a2;
        ma = max(ma,abs(a2-a1));
        a1 = a2;
    }
    ma=max(ma,a0+k-a2);
    cout << k-ma << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}