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
    ll n,m; cin >> n>>m;
    vector<bool> ac(n,false);
    vector<ll> wa(n,0);
    rep(i,m){
        ll p; cin >> p;
        string s ; cin >> s;
        if(s=="AC") ac[p-1]=true;
        else if(!ac[p-1]) wa[p-1]++;
    }
    ll acs=0,pas=0;
    rep(i,n){
        if(ac[i]){acs++;pas+=wa[i];}
    }
    cout << acs << ' ' << pas <<endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}