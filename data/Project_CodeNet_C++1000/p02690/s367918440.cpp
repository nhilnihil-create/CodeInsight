#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<cmath>
#include <iomanip>

typedef unsigned long long ull;
typedef long long ll;

ll DENOM = 1000000000LL + 7LL;
ll D2 = 998244353LL;
using namespace std;

ll n, m, k;
ll pow5(ll x){
    ll ret = x*x*x*x*x;
    return ret;
}
ll pow4(ll x){
    ll ret = x*x*x*x;
    return ret;
}

int main(){
    cin >> n;
    ll a,b;
    ll mx = ceil(sqrt(sqrt(n)));
    for(ll i=1;i < mx+1; ++i){
        for(ll j=0; j<mx+1; ++j){
            if(pow5(i) - pow5(j) == n){
                a = i;
                b = j;
                break;
            }else if(pow5(i) + pow5(j) == n){
                a = i;
                b = -j;
                break;
            }
        }
    }
    cout << a << " " << b << endl;

    return 0;
}